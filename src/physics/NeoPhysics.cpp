/*
 * NeoPhysics.cpp
 *
 *  Created on: 2016年2月15日
 *      Author: neo
 */

#include "NeoPhysics.h"
#include "BasicExplosionPhysics.h"
//#include<algorithm>

NeoPhysics* NeoPhysics::_instance = NULL;

NeoPhysics::NeoPhysics()
{
	fTimeScale = 1;
	fWorldScale = 1;
}

NeoPhysics* NeoPhysics::getInstance()
{
	if (!_instance)
	{
		_instance = new NeoPhysics();
	}
	return _instance;
}

void NeoPhysics::Destroy()
{
	if (_instance)
	{
		delete _instance;
		_instance = NULL;
	}

}

void NeoPhysics::Init()
{
	m_collisionConfiguration = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);
	m_broadphase = new btDbvtBroadphase();
	btSequentialImpulseConstraintSolver* sol =
			new btSequentialImpulseConstraintSolver;
	m_solver = sol;
	m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase,
			m_solver, m_collisionConfiguration);

	m_dynamicsWorld->setGravity(btVector3(0, -10, 0));
	m_dynamicsWorld->getSolverInfo().m_solverMode |=
			SOLVER_ENABLE_FRICTION_DIRECTION_CACHING;
	//ghost object collision detection
	m_ghostpairCallback = shared_ptr < btGhostPairCallback
			> (new btGhostPairCallback());
	m_dynamicsWorld->getBroadphase()->getOverlappingPairCache()->setInternalGhostPairCallback(
			m_ghostpairCallback.get());
	//---Explosion creators---//
	RegisterExplosionCreator("BasicExplosionPhysics",
			BasicExplosionPhysics::Create);
}

void NeoPhysics::Update(float timestep)
{
	if (fTimeScale > 0)
	{
		m_dynamicsWorld->stepSimulation(timestep * fTimeScale);
		int numManifolds = m_dynamicsWorld->getDispatcher()->getNumManifolds();
		std::set<std::pair<GameObject*, GameObject*>> new_contacts;
		for (int i = 0; i < numManifolds; i++)
		{
			btPersistentManifold * contactManifold =
					m_dynamicsWorld->getDispatcher()->getManifoldByIndexInternal(
							i);
			btCollisionObject* obj_a =
					const_cast<btCollisionObject*>(contactManifold->getBody0());
			btCollisionObject* obj_b =
					const_cast<btCollisionObject*>(contactManifold->getBody1());
			if (contactManifold->getNumContacts() > 0)
			{
				/* do some stuff here with the objects and contact points */
				GameObject*go_a =
						static_cast<GameObject*>(obj_a->getUserPointer());
				GameObject*go_b =
						static_cast<GameObject*>(obj_b->getUserPointer());
				if (!go_a || !go_b)
					continue;
				new_contacts.insert(
						std::make_pair<GameObject*, GameObject*>(
								static_cast<GameObject*>(obj_a->getUserPointer()),
								static_cast<GameObject*>(obj_b->getUserPointer())));
				go_a->OnContactCallback(contactManifold, go_b);
				go_b->OnContactCallback(contactManifold, go_a);

			}
		}

		//modified from std::set_intersection
		//complexity O(n)=max(m,n)
		std::set<std::pair<GameObject*, GameObject*>>::iterator
				iter_new_contact = new_contacts.begin(), iter_new_contact_end =
						new_contacts.end();
		std::set<std::pair<GameObject*, GameObject*>>::iterator iter_contact =
				m_contact.begin(), iter_contact_end = m_contact.end();
		while (iter_new_contact != iter_new_contact_end
				|| iter_contact != iter_contact_end)
		{
			//旧contact没有了，剩下的新contact全部执行collisionenter
			if (iter_contact == iter_contact_end)
			{
				while (iter_new_contact != iter_new_contact_end)
				{
					iter_new_contact->first->OnCollisionEnter(
							iter_new_contact->second);
					iter_new_contact->second->OnCollisionEnter(
							iter_new_contact->first);
					++iter_new_contact;
				}
				break;
			}
			//新contact没有了，剩下的旧contact全部执行collisionexit
			if (iter_new_contact == iter_new_contact_end)
			{
				while (iter_contact != iter_contact_end)
				{
					iter_contact->first->OnCollisionExit(iter_contact->second);
					iter_contact->second->OnCollisionExit(iter_contact->first);
					++iter_contact;
				}
				break;
			}
			//以上两种情况都不存在，则进行正常比较
			if (*iter_new_contact < *iter_contact)
			{
				iter_new_contact->first->OnCollisionEnter(
						iter_new_contact->second);
				iter_new_contact->second->OnCollisionEnter(
						iter_new_contact->first);
				++iter_new_contact;
			}
			else if (*iter_contact < *iter_new_contact)
			{
				iter_contact->first->OnCollisionExit(iter_contact->second);
				iter_contact->second->OnCollisionExit(iter_contact->first);
				++iter_contact;
			}
			else
			{
				iter_contact->first->OnCollision(iter_contact->second);
				iter_contact->second->OnCollision(iter_contact->first);
				++iter_new_contact;
				++iter_contact;
			}
		}

		//alternative algorithm use stl set function, complexicy O(n)=3n
		/*	std::set<std::pair<GameObject*, GameObject*>> collEnter;
		 std::set<std::pair<GameObject*, GameObject*>> coll;
		 std::set<std::pair<GameObject*, GameObject*>> collExit;
		 std::set_difference(new_contacts.begin(), new_contacts.end(),
		 m_contact.begin(), m_contact.end(),
		 std::inserter(collEnter, collEnter.begin()));
		 std::set_difference(m_contact.begin(), m_contact.end(),
		 new_contacts.begin(), new_contacts.end(),
		 std::inserter(collExit, collExit.begin()));
		 std::set_intersection(m_contact.begin(), m_contact.end(),
		 new_contacts.begin(), new_contacts.end(),
		 std::inserter(coll, coll.begin()));
		 std::set<std::pair<GameObject*, GameObject*>>::iterator iter;
		 //----------------collision call back------------------//
		 for (iter = collEnter.begin(); iter != collEnter.end(); iter++)
		 {
		 iter->first->OnCollisionEnter(iter->second);
		 iter->second->OnCollisionEnter(iter->first);
		 }
		 for (iter = coll.begin(); iter != coll.end(); iter++)
		 {
		 iter->first->OnCollision(iter->second);
		 iter->second->OnCollision(iter->first);
		 }
		 for (iter = collExit.begin(); iter != collExit.end(); iter++)
		 {
		 iter->first->OnCollisionExit(iter->second);
		 iter->second->OnCollisionExit(iter->first);
		 }*/
		//---------------------------------------//
		m_contact = new_contacts;
		//------ghost objects---------//
		for (std::map<int, GhostObject*>::iterator iter =
				m_activeGhostObjects.begin();
				iter != m_activeGhostObjects.end(); iter++)
		{
			int index = iter->first;
			GhostObject* ghostObject = iter->second;
			if (ghostObject->isActive())
			{
				m_ghostObjectCallbacks[index](ghostObject,
						ghostObject->getBtGhostObject()->getOverlappingPairs());
			}
		}
		PostProcessingCall();
	}
}

void NeoPhysics::CleanUp()
{
//order matters
	//removed/delete constraints
	for (int i = m_dynamicsWorld->getNumConstraints() - 1; i >= 0; i--)
	{
		btTypedConstraint* constraint = m_dynamicsWorld->getConstraint(i);
		m_dynamicsWorld->removeConstraint(constraint);
	}
	//clean all the ghost objects
	for (std::vector<std::shared_ptr<btGhostObject>>::iterator iter =
			m_ghostObjects.begin(); iter != m_ghostObjects.end(); iter++)
	{
		m_dynamicsWorld->removeCollisionObject((*iter).get());
	}
	//clean up all ghost object callbacks
	m_ghostObjectCallbacks.clear();
//clean all the rigid bodies
	for (std::vector<std::shared_ptr<btRigidBody>>::iterator iter =
			m_rigidBodies.begin(); iter != m_rigidBodies.end(); iter++)
	{
		m_dynamicsWorld->removeRigidBody((*iter).get());
	}
	m_contact.clear();
	m_constrains.clear();
	m_rigidBodies.clear();
	m_ghostObjects.clear();
	m_motionStates.clear();
	m_collisionShapes.clear();
	m_triangleMeshes.clear();
	m_activeGhostObjects.clear();

	m_areaDetectGhostObjectPool.Clear();

	m_available_shapes.clear();
	m_available_rigidbody.clear();
	m_available_ghostObjects.clear();
	m_available_Constraints.clear();
}

int NeoPhysics::CreateSphereShape(float radius,
		const irr::core::vector3df& scale)
{
	std::shared_ptr<btCollisionShape> ptr(new btSphereShape(radius * scale.X));
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateBoxShape(irr::core::vector3df& size,
		const irr::core::vector3df& scale)
{
	irr::core::vector3df size_real = size * scale;
	btVector3 halfext(size_real.X * 0.5f, size_real.Y * 0.5f,
			size_real.Z * 0.5f);
	std::shared_ptr<btCollisionShape> ptr(new btBoxShape(halfext));
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateCylinderShape(irr::core::vector3df& extents, char align,
		const irr::core::vector3df& scale)
{
	irr::core::vector3df extents_real = extents * scale;
	btVector3 halfext(extents_real.X * 0.5f, extents_real.Y * 0.5f,
			extents_real.Z * 0.5f);
	std::shared_ptr<btCollisionShape> ptr;
	switch (align)
	{
	case 'X':
	case 'x':
		ptr = std::shared_ptr < btCollisionShape
				> (new btCylinderShapeX(halfext));
		break;
	case 'Y':
	case 'y':
		ptr = std::shared_ptr < btCollisionShape
				> (new btCylinderShape(halfext));
		break;
	case 'Z':
	case 'z':
		ptr = std::shared_ptr < btCollisionShape
				> (new btCylinderShapeZ(halfext));
		break;
	default:
		ptr = std::shared_ptr < btCollisionShape
				> (new btCylinderShape(halfext));
		break;
	}
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateCapsuleShape(float radius, float height, char align,
		const irr::core::vector3df& scale)
{
	std::shared_ptr<btCollisionShape> ptr;
	switch (align)
	{
	case 'X':
	case 'x':
		ptr = std::shared_ptr < btCollisionShape
				> (new btCapsuleShapeX(radius * scale.Y, height * scale.X));
		break;
	case 'Y':
	case 'y':
		ptr = std::shared_ptr < btCollisionShape
				> (new btCapsuleShape(radius * scale.X, height * scale.Y));
		break;
	case 'Z':
	case 'z':
		ptr = std::shared_ptr < btCollisionShape
				> (new btCapsuleShapeZ(radius * scale.Y, height * scale.Z));
		break;
	default:
		ptr = std::shared_ptr < btCollisionShape
				> (new btCapsuleShape(radius * scale.X, height * scale.Y));
		break;
	}
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateConeShape(float radius, float height, char align,
		const irr::core::vector3df& scale)
{
	std::shared_ptr<btCollisionShape> ptr;
	switch (align)
	{
	case 'X':
	case 'x':
		ptr = std::shared_ptr < btCollisionShape
				> (new btConeShapeX(radius * scale.Y, height * scale.X));
		break;
	case 'Y':
	case 'y':
		ptr = std::shared_ptr < btCollisionShape
				> (new btConeShape(radius * scale.X, height * scale.Y));
		break;
	case 'Z':
	case 'z':
		ptr = std::shared_ptr < btCollisionShape
				> (new btConeShapeZ(radius * scale.Y, height * scale.Z));
		break;
	default:
		ptr = std::shared_ptr < btCollisionShape
				> (new btConeShape(radius * scale.X, height * scale.Y));
		break;
	}
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateMultiSphereShape(irr::core::vector3df positions[],
		float radiuses[], int numSpheres)
{
	btVector3 btPositions[numSpheres];
	for (int i = 0; i < numSpheres; i++)
	{
		btPositions[i] = btVector3(positions[1].X, positions[i].Y,
				positions[i].Z);
	}
	std::shared_ptr<btCollisionShape> ptr(
			new btMultiSphereShape(btPositions, radiuses, numSpheres));
	return assignShapeIndex(ptr);
}

NeoPhysics::~NeoPhysics()
{
// TODO 自动生成的析构函数存根
	CleanUp();

	delete m_dynamicsWorld;

	delete m_solver;

	delete m_broadphase;

	delete m_dispatcher;

	delete m_collisionConfiguration;
}

const btBroadphaseInterface* NeoPhysics::getBroadphase()
{
	return m_broadphase;
}

void NeoPhysics::setBroadphase(btBroadphaseInterface* broadphase)
{
	m_broadphase = broadphase;
}

const btDefaultCollisionConfiguration* NeoPhysics::getCollisionConfiguration()
{
	return m_collisionConfiguration;
}

void NeoPhysics::setCollisionConfiguration(
		btDefaultCollisionConfiguration* collisionConfiguration)
{
	m_collisionConfiguration = collisionConfiguration;
}

const btCollisionDispatcher* NeoPhysics::getDispatcher()
{
	return m_dispatcher;
}

void NeoPhysics::setDispatcher(btCollisionDispatcher* dispatcher)
{
	m_dispatcher = dispatcher;
}

const btDiscreteDynamicsWorld* NeoPhysics::getDynamicsWorld()
{
	return m_dynamicsWorld;
}

void NeoPhysics::setDynamicsWorld(btDiscreteDynamicsWorld* dynamicsWorld)
{
	m_dynamicsWorld = dynamicsWorld;
}

const btConstraintSolver* NeoPhysics::getSolver()
{
	return m_solver;
}

void NeoPhysics::setSolver(btConstraintSolver* solver)
{
	m_solver = solver;
}

int NeoPhysics::getTimescale() const
{
	return fTimeScale;
}

void NeoPhysics::setTimescale(float timescale)
{
	fTimeScale = timescale;
}

float NeoPhysics::getWorldScale() const
{
	return fWorldScale;
}

void NeoPhysics::setWorldScale(float worldScale)
{
	fWorldScale = worldScale;
}

int NeoPhysics::assignShapeIndex(std::shared_ptr<btCollisionShape>&ptr)
{
	if (m_available_shapes.empty())
	{
		m_collisionShapes.push_back(ptr);
		return m_collisionShapes.size() - 1;
	}
	else
	{
		int index = m_available_shapes.front();
		m_available_shapes.pop_front();
		m_collisionShapes[index] = ptr;
		return index;
	}
}

std::shared_ptr<btCollisionShape> NeoPhysics::getCollisionShape(int index)
{
	if (index >= 0 && index < m_collisionShapes.size())
		return m_collisionShapes[index];
	else
		return NULL;
}

std::shared_ptr<btRigidBody> NeoPhysics::getRigidBody(int index)
{
	if (index >= 0 && index < m_rigidBodies.size())
		return m_rigidBodies[index];
	else
		return NULL;
}

std::shared_ptr<btTypedConstraint> NeoPhysics::getConstraint(int index)
{
	if (index >= 0 && index < m_constrains.size())
		return m_constrains[index];
	else
		return NULL;
}

int NeoPhysics::CreateConvexHullShape(irr::scene::IMesh*mesh,
		irr::core::vector3df scale)
{
	int i, j;
	int numVertices;
	btConvexHullShape *hullShape = new btConvexHullShape();
	irr::scene::IMesh* collMesh = mesh;
	for (i = 0; i < collMesh->getMeshBufferCount(); i++)
	{
		auto mb = collMesh->getMeshBuffer(i);

		//////////////////////////////////////////////////////////////////////////
		// Extract vertex data                                                  //
		// Because the vertices are stored as structs with no common base class,//
		// We need to handle each type separately                               //
		//////////////////////////////////////////////////////////////////////////
		if (mb->getVertexType() == irr::video::EVT_STANDARD)
		{
			auto mb_vertices = (irr::video::S3DVertex*) mb->getVertices();
			numVertices = mb->getVertexCount();
			for (j = 0; j < numVertices; j++)
			{
				irr::core::vector3df v = mb_vertices[j].Pos * scale;
				hullShape->addPoint(irrToBulletVector(v));
			}

		}
		else if (mb->getVertexType() == irr::video::EVT_2TCOORDS)
		{
			// Same but for S3DVertex2TCoords data
			auto mb_vertices =
					(irr::video::S3DVertex2TCoords*) mb->getVertices();
			int numVertices = mb->getVertexCount();
			for (j = 0; j < numVertices; j++)
			{
				irr::core::vector3df v = mb_vertices[j].Pos * scale;
				hullShape->addPoint(irrToBulletVector(v));
			}
		}

		// Does not handle the EVT_TANGENTS type
	}
	std::shared_ptr<btCollisionShape> ptr(hullShape);
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateConvexTriangleMeshShape(irr::scene::IMesh*mesh,
		irr::core::vector3df scale)
{
	if (mesh)
	{
		btTriangleMesh* btMesh = createTriangleMesh(mesh, scale);
		auto shape = new btConvexTriangleMeshShape(btMesh);
		std::shared_ptr<btCollisionShape> ptr(shape);
		return assignShapeIndex(ptr);
	}
	return -1;
}

int NeoPhysics::CreateBvhTriangleShape(irr::scene::IMesh*mesh,
		irr::core::vector3df scale)
{
	if (mesh)
	{
		btTriangleMesh* btMesh = createTriangleMesh(mesh, scale);
		auto shape = new btBvhTriangleMeshShape(btMesh, false, true);
		std::shared_ptr<btCollisionShape> ptr(shape);
		return assignShapeIndex(ptr);
	}
	return -1;
}

//int NeoPhysics::CreateHeightfieldTerrainShape(int meshIndex)
//{
//
//}

int NeoPhysics::assignRigidBodyIndex(std::shared_ptr<btRigidBody>&ptr)
{
	if (m_available_rigidbody.empty())
	{
		m_rigidBodies.push_back(ptr);
		return m_rigidBodies.size() - 1;
	}
	else
	{
		int index = m_available_rigidbody.front();
		m_available_rigidbody.pop_front();
		m_rigidBodies[index] = ptr;
		return index;
	}
}

NeoPhysics::RaycastResult NeoPhysics::RayCast(const irr::core::vector3df& from,
		const irr::core::vector3df& to)
{
	RaycastResult result;
	btVector3 origin = irrToBulletVector(from);
	btVector3 target = irrToBulletVector(to);
	btCollisionWorld::ClosestRayResultCallback RayCallback(origin, target);
	m_dynamicsWorld->rayTest(origin, target, RayCallback);
	result.hasHit = RayCallback.hasHit();
	if (result.hasHit)
	{
		result.m_gameObject = static_cast<GameObject*>(RayCallback.m_collisionObject->getUserPointer());
		result.m_hitNormalWorld = bulletToIrrVector(RayCallback.m_hitNormalWorld);
		result.m_hitPointWorld = bulletToIrrVector(RayCallback.m_hitPointWorld);
	}
	else
	{
		result.m_gameObject = NULL;
		result.m_hitPointWorld = vector3df(0, 0, 0);
		result.m_hitNormalWorld = vector3df(0, 0, 0);
	}
	return result;
}

btTriangleMesh* NeoPhysics::createTriangleMesh(irr::scene::IMesh*mesh,
		vector3df scale, int*assignedIndex)
{
	btVector3 vertices[3];
	int i, j, k;
	int index, numVertices;
	short* mb_indices;

	auto pTriMesh = new btTriangleMesh();

	for (i = 0; i < mesh->getMeshBufferCount(); i++)
	{
		auto mb = mesh->getMeshBuffer(i);

		//////////////////////////////////////////////////////////////////////////
		// Extract vertex data                                                  //
		// Because the vertices are stored as structs with no common base class,//
		// We need to handle each type separately                               //
		//////////////////////////////////////////////////////////////////////////
		if (mb->getVertexType() == irr::video::EVT_STANDARD)
		{
			auto mb_vertices = (irr::video::S3DVertex*) mb->getVertices();
			mb_indices = mb->getIndices();
			numVertices = mb->getVertexCount();
			for (j = 0; j < mb->getIndexCount(); j += 3)
			{ //get index into vertex list
				for (k = 0; k < 3; k++)
				{
					//three verts per triangle
					index = mb_indices[j + k];
					if (index > numVertices)
						continue;
					//convert to btVector3
					irr::core::vector3df v = mb_vertices[index].Pos * scale;
					vertices[k] = irrToBulletVector(v); // 1100
				}
				pTriMesh->addTriangle(vertices[0], vertices[1], vertices[2]);
			}

		}
		else if (mb->getVertexType() == irr::video::EVT_2TCOORDS)
		{
			// Same but for S3DVertex2TCoords data
			auto mb_vertices =
					(irr::video::S3DVertex2TCoords*) mb->getVertices();
			short* mb_indices = mb->getIndices();
			int numVertices = mb->getVertexCount();
			for (j = 0; j < mb->getIndexCount(); j += 3)
			{
				//index into irrlicht data
				for (k = 0; k < 3; k++)
				{
					s32 index = mb_indices[j + k];
					if (index > numVertices)
						continue;
					irr::core::vector3df v = mb_vertices[index].Pos * scale;
					vertices[k] = irrToBulletVector(v);
				}
				pTriMesh->addTriangle(vertices[0], vertices[1], vertices[2]);
			}
		}

		// Does not handle the EVT_TANGENTS type
	}

	shared_ptr<btTriangleMesh> ptr(pTriMesh);
	m_triangleMeshes.push_back(ptr);
	if (assignedIndex)
		*assignedIndex = m_triangleMeshes.size() - 1;
	return pTriMesh;
}

int NeoPhysics::CreateCompoundShape()
{
	btCompoundShape* shape = new btCompoundShape();
	shared_ptr<btCollisionShape> ptr(shape);
	return assignShapeIndex(ptr);
}

void NeoPhysics::CompoundShapeAddChild(int shapeIndex, int childIndex,
		irr::core::vector3df localPos, irr::core::vector3df localRotation)
{
	btTransform trans;
	trans.setIdentity();
	trans.setOrigin(irrToBulletVector(localPos));
	irr::core::quaternion qrot(localRotation * DEGTORAD);
	trans.setRotation(btQuaternion(qrot.X, qrot.Y, qrot.Z, qrot.W));
	std::shared_ptr<btCollisionShape> pChild = getCollisionShape(childIndex);
	static_cast<btCompoundShape*>(getCollisionShape(shapeIndex).get())->addChildShape(
			trans, pChild.get());
}

RigidBody* NeoPhysics::CreateRigidBody(int collisionShapeIndex,
		irr::scene::ISceneNode*node, float mass,
		irr::core::vector3df pos /*= 	irr::core::vector3df(0, 0, 0)*/,
		irr::core::vector3df rotation /*=
		 irr::core::vector3df(0, 0, 0)*/)
{
	shared_ptr<btRigidBody> ptr = CreateRigidBody_cpp_api(collisionShapeIndex,
			node, mass, pos, rotation);
	int index = assignRigidBodyIndex(ptr);
	RigidBody*rgdbody = new RigidBody(ptr);
	rgdbody->setInternalIndex(index);
	return rgdbody;
}

shared_ptr<btRigidBody> NeoPhysics::CreateRigidBody_cpp_api(
		int collisionShapeIndex, irr::scene::ISceneNode* node, float mass,
		irr::core::vector3df pos, irr::core::vector3df rotation)
{
	std::shared_ptr<btCollisionShape> pColl = getCollisionShape(
			collisionShapeIndex);
	btVector3 localInertia(0, 0, 0);
	if (mass > 0.0f)
		pColl->calculateLocalInertia(mass, localInertia);

	NeoMotionState* ms = new NeoMotionState();
	ms->setNode(node);
	std::shared_ptr<NeoMotionState> pMotion(ms);
	m_motionStates.insert(pMotion);
	btRigidBody* rbody = new btRigidBody(mass, ms, pColl.get(), localInertia);
	//set initial transform
	irr::core::matrix4 mat;
	mat.makeIdentity();
	mat.setTranslation(pos);
	mat.setRotationDegrees(rotation);
	btTransform btTrans;
	IrrlichtMatrixTobtTransform(mat, btTrans);
	rbody->setWorldTransform(btTrans);

	std::shared_ptr<btRigidBody> ptr(rbody);
	return ptr;
}

HingeJoint* NeoPhysics::CreateHingeJoint(RigidBody* rigidbody1,
		RigidBody* rigidbody2, irr::core::vector3df pivot1,
		irr::core::vector3df pivot2, irr::core::vector3df axisIn1,
		irr::core::vector3df axisIn2)
{
	btRigidBody*bodyA = rigidbody1->getBtRigidBody().get();
	btRigidBody*bodyB = rigidbody2->getBtRigidBody().get();
	if (!bodyA || !bodyB)
		return NULL;
	std::shared_ptr<btTypedConstraint> ptr = CreateHingeJoint_cpp_api(
			rigidbody1->getBtRigidBody(), rigidbody2->getBtRigidBody(), pivot1,
			pivot2, axisIn1, axisIn2);
	int index = assignConstraintIndex(ptr);
	HingeJoint*joint = new HingeJoint(
			dynamic_pointer_cast < btHingeConstraint > (ptr), rigidbody1,
			rigidbody2);
	joint->setInternalIndex(index);
	return joint;
}

HingeJoint* NeoPhysics::CreateHingeJoint(RigidBody* body,
		irr::core::vector3df pivot, irr::core::vector3df axis)
{
	if (body == NULL)
		return NULL;
	std::shared_ptr<btTypedConstraint> ptr = CreateHingeJoint_cpp_api(
			body->getBtRigidBody(), pivot, axis);
	int index = assignConstraintIndex(ptr);
	HingeJoint*joint = new HingeJoint(
			dynamic_pointer_cast < btHingeConstraint > (ptr), body,
			NULL);
	joint->setInternalIndex(index);
	return joint;
}

shared_ptr<btTypedConstraint> NeoPhysics::CreateHingeJoint_cpp_api(
		shared_ptr<btRigidBody> rigidbody1, shared_ptr<btRigidBody> rigidbody2,
		irr::core::vector3df pivot1, irr::core::vector3df pivot2,
		irr::core::vector3df axisIn1, irr::core::vector3df axisIn2)
{
	btHingeConstraint* hinge = new btHingeConstraint(*rigidbody1.get(),
			*rigidbody2.get(), irrToBulletVector(pivot1),
			irrToBulletVector(pivot2), irrToBulletVector(axisIn1),
			irrToBulletVector(axisIn2));
	std::shared_ptr<btTypedConstraint> ptr(hinge);
	return ptr;
}

shared_ptr<btTypedConstraint> NeoPhysics::CreateHingeJoint_cpp_api(
		shared_ptr<btRigidBody> body, irr::core::vector3df pivot,
		irr::core::vector3df axis)
{
	btHingeConstraint* hinge = new btHingeConstraint(*body.get(),
			irrToBulletVector(pivot), irrToBulletVector(axis));
	std::shared_ptr<btTypedConstraint> ptr(hinge);
	return ptr;
}

int NeoPhysics::assignConstraintIndex(std::shared_ptr<btTypedConstraint>& ptr)
{
	if (m_available_Constraints.empty())
	{
		m_constrains.push_back(ptr);
		return m_constrains.size() - 1;
	}
	else
	{
		int index = m_available_Constraints.front();
		m_available_Constraints.pop_front();
		m_constrains[index] = ptr;
		return index;
	}
}

void NeoPhysics::RemoveJoint(int index)
{
	m_dynamicsWorld->removeConstraint(m_constrains[index].get());
	m_available_Constraints.push_back(index);
	m_constrains[index] = NULL;
}

void NeoPhysics::PostProcessingCall()
{
	m_areaDetectGhostObjectPool.RecyleAll();
}

void NeoPhysics::RemoveCollisionShape(int index)
{
	m_available_shapes.push_back(index);
	m_collisionShapes[index] = NULL;
}

void NeoPhysics::RemoveRigidBody(int index)
{
	m_dynamicsWorld->removeRigidBody(m_rigidBodies[index].get());
	m_available_rigidbody.push_back(index);
	m_rigidBodies[index] = NULL;
}

GhostObject* NeoPhysics::CreateGhostObject(int collisionSahpIndex,
		std::function<
				void(GhostObject*, btAlignedObjectArray<btCollisionObject*>&)> overlapCallback,
		irr::core::vector3df pos, irr::core::vector3df rotation)
{
	btGhostObject* go = new btGhostObject();
	go->setCollisionShape(m_collisionShapes[collisionSahpIndex].get());
	go->setCollisionFlags(
			go->getCollisionFlags()
					| btCollisionObject::CF_NO_CONTACT_RESPONSE);
	//set transform
	irr::core::matrix4 mat;
	mat.makeIdentity();
	mat.setTranslation(pos);
	mat.setRotationDegrees(rotation);
	btTransform btTrans;
	IrrlichtMatrixTobtTransform(mat, btTrans);
	go->setWorldTransform(btTrans);
	std::shared_ptr<btGhostObject> ptr(go);
	int index = assignGhostBodyIndex(ptr, overlapCallback);

	GhostObject* ghostObject = new GhostObject(ptr);
	ghostObject->setInternalIndex(index);
	AddActiveGhostObject(ghostObject);
	return ghostObject;
}

void NeoPhysics::AddActiveGhostObject(GhostObject* obj)
{
	m_activeGhostObjects[obj->getInternalIndex()] = obj;
}

void NeoPhysics::RemoveActiveGhostObject(GhostObject* obj)
{
	if (m_activeGhostObjects.count(obj->getInternalIndex()) > 0)
	{
		m_activeGhostObjects.erase(obj->getInternalIndex());
	}
}

int NeoPhysics::assignGhostBodyIndex(std::shared_ptr<btGhostObject>& ptr,
		std::function<
				void(GhostObject*, btAlignedObjectArray<btCollisionObject*>&)> overlapCallback)
{
	if (m_available_ghostObjects.empty())
	{
		m_ghostObjects.push_back(ptr);
		m_ghostObjectCallbacks.push_back(overlapCallback);
		return m_ghostObjects.size() - 1;
	}
	else
	{
		int index = m_available_ghostObjects.front();
		m_available_ghostObjects.pop_front();
		m_ghostObjects[index] = ptr;
		m_ghostObjectCallbacks[index] = overlapCallback;
		return index;
	}
}

void NeoPhysics::RemoveGhostObject(int index)
{
	m_dynamicsWorld->removeCollisionObject(m_ghostObjects[index].get());
	m_available_ghostObjects.push_back(index);
	m_ghostObjects[index] = NULL;
}

void NeoPhysics::GetObjectsInArea(float radius, irr::core::vector3df pos,
		std::function<
				void(GhostObject*, btAlignedObjectArray<btCollisionObject*>&)> callback)
{
	std::shared_ptr<GhostObject> ptr = m_areaDetectGhostObjectPool.Create(
			radius, pos, callback);
	m_areaDetectGhostObjectPool.AddToRecycleQueue(ptr);
}

void NeoPhysics::AddRigidiBodyToWorld(RigidBody* rigidbody)
{
	m_dynamicsWorld->addRigidBody(rigidbody->getBtRigidBody().get());
}

void NeoPhysics::AddHingeJointToWorld(HingeJoint* hinge,
		bool disableCollisionsBetweenLinkedBodies)
{
	AddJointToWorld_cpp(hinge->getHinge(),
			disableCollisionsBetweenLinkedBodies);
}

void NeoPhysics::AddJointToWorld_cpp(shared_ptr<btTypedConstraint> constraint,
		bool disableCollisionsBetweenLinkedBodies)
{
	m_dynamicsWorld->addConstraint(constraint.get(),
			disableCollisionsBetweenLinkedBodies);
}

void NeoPhysics::RemoveRigidBodyFromWorld(RigidBody* rigidbody)
{
	m_dynamicsWorld->removeRigidBody(rigidbody->getBtRigidBody().get());
}

void NeoPhysics::RemoveJointFromWorld(int index)
{
	m_dynamicsWorld->removeConstraint(m_constrains[index].get());
}

void NeoPhysics::AddCollisionObjectToWorld(CollisionObject* collisionObj)
{
	m_dynamicsWorld->addCollisionObject(
			collisionObj->getBtCollisionObject().get());
}

void NeoPhysics::RemoveCollisionObjectFromWorld(CollisionObject* collisionObj)
{
	m_dynamicsWorld->removeCollisionObject(
			collisionObj->getBtCollisionObject().get());
}

void NeoPhysics::RemoveHingeJointFromWorld(HingeJoint* hinge)
{
	RemoveJointFromWorld(hinge->getInternalIndex());
}

std::shared_ptr<btTriangleMesh> NeoPhysics::getTriangleMesh(int index)
{
	if (index >= 0 && index < m_triangleMeshes.size())
		return m_triangleMeshes[index];
	return NULL;
}

std::shared_ptr<ExplosionPhysics> NeoPhysics::CreateExplosion(std::string type,
		NeoData& params)
{
	if (d_explosion_type.count(type) > 0)
	{
		return d_explosion_type[type](params);
	}
	//return empty pointer if failed to find type
	return std::shared_ptr<ExplosionPhysics>();
}

void NeoPhysics::RegisterExplosionCreator(std::string type,
		std::function<std::shared_ptr<ExplosionPhysics>(NeoData&)> functor)
{
	d_explosion_type[type] = functor;
}

void NeoPhysics::GhostObjectSetOverLapCallback(GhostObject* obj,
		std::function<
				void(GhostObject*, btAlignedObjectArray<btCollisionObject*> &)> overlapCallback)
{
	int index = obj->getInternalIndex();
	if (index >= 0)
		m_ghostObjectCallbacks[index] = overlapCallback;
}
