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
	// TODO 自动生成的构造函数存根
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
	//ghost object collision detection
	m_ghostpairCallback = shared_ptr<btGhostPairCallback>(
			new btGhostPairCallback());
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
		PreProcessingCall();
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
		int i = 0;
		for (std::vector<std::shared_ptr<btGhostObject>>::iterator iter =
				m_ghostObjects.begin(); iter != m_ghostObjects.end();
				iter++, i++)
		{
			int n_obj = iter->get()->getNumOverlappingObjects();
			if (n_obj > 0)
			{
				m_ghostObjectCallbacks[i](i,
						iter->get()->getOverlappingPairs());
			}
		}
		//clean up temporary collision shapes
		for (i = 0; i < m_temporaryCollisionShaps.size(); i++)
		{
			RemoveCollisionShape(m_temporaryCollisionShaps[i]);
		}
		m_temporaryCollisionShaps.clear();
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

	m_temporaryCollisionShaps.clear();

	m_available_shapes.clear();
	m_available_rigidbody.clear();
	m_available_ghostObjects.clear();
	m_available_Constraints.clear();
}

int NeoPhysics::CreateSphereShape(float radius, const irr::core::vector3df& scale)
{
	std::shared_ptr<btCollisionShape> ptr(new btSphereShape(radius*scale.X));
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateBoxShape(irr::core::vector3df& size, const irr::core::vector3df& scale)
{
	irr::core::vector3df size_real=size*scale;
	btVector3 halfext(size_real.X * 0.5f, size_real.Y * 0.5f, size_real.Z * 0.5f);
	std::shared_ptr<btCollisionShape> ptr(new btBoxShape(halfext));
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateCylinderShape(irr::core::vector3df& extents, char align, const irr::core::vector3df& scale)
{
	irr::core::vector3df extents_real=extents*scale;
	btVector3 halfext(extents_real.X * 0.5f, extents_real.Y * 0.5f, extents_real.Z * 0.5f);
	std::shared_ptr<btCollisionShape> ptr;
	switch (align)
	{
	case 'X':
	case 'x':
		ptr = std::shared_ptr<btCollisionShape>(new btCylinderShapeX(halfext));
		break;
	case 'Y':
	case 'y':
		ptr = std::shared_ptr<btCollisionShape>(new btCylinderShape(halfext));
		break;
	case 'Z':
	case 'z':
		ptr = std::shared_ptr<btCollisionShape>(new btCylinderShapeZ(halfext));
		break;
	default:
		ptr = std::shared_ptr<btCollisionShape>(new btCylinderShape(halfext));
		break;
	}
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateCapsuleShape(float radius, float height, char align, const irr::core::vector3df& scale)
{
	std::shared_ptr<btCollisionShape> ptr;
	switch (align)
	{
	case 'X':
	case 'x':
		ptr = std::shared_ptr<btCollisionShape>(
				new btCapsuleShapeX(radius*scale.Y, height*scale.X));
		break;
	case 'Y':
	case 'y':
		ptr = std::shared_ptr<btCollisionShape>(
				new btCapsuleShape(radius*scale.X, height*scale.Y));
		break;
	case 'Z':
	case 'z':
		ptr = std::shared_ptr<btCollisionShape>(
				new btCapsuleShapeZ(radius*scale.Y, height*scale.Z));
		break;
	default:
		ptr = std::shared_ptr<btCollisionShape>(
				new btCapsuleShape(radius*scale.X, height*scale.Y));
		break;
	}
	return assignShapeIndex(ptr);
}

int NeoPhysics::CreateConeShape(float radius, float height, char align, const irr::core::vector3df& scale)
{
	std::shared_ptr<btCollisionShape> ptr;
	switch (align)
	{
	case 'X':
	case 'x':
		ptr = std::shared_ptr<btCollisionShape>(
				new btConeShapeX(radius*scale.Y, height*scale.X));
		break;
	case 'Y':
	case 'y':
		ptr = std::shared_ptr<btCollisionShape>(
				new btConeShape(radius*scale.X, height*scale.Y));
		break;
	case 'Z':
	case 'z':
		ptr = std::shared_ptr<btCollisionShape>(
				new btConeShapeZ(radius*scale.Y, height*scale.Z));
		break;
	default:
		ptr = std::shared_ptr<btCollisionShape>(
				new btConeShape(radius*scale.X, height*scale.Y));
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

int NeoPhysics::CreateRigidBody(int collisionShapeIndex,
		irr::scene::ISceneNode*node, float mass,
		irr::core::vector3df pos /*= 	irr::core::vector3df(0, 0, 0)*/,
		irr::core::vector3df rotation /*=
		 irr::core::vector3df(0, 0, 0)*/)
{
	std::shared_ptr<btCollisionShape> pColl = getCollisionShape(
			collisionShapeIndex);
	btVector3 localInertia(0, 0, 0);
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
	return assignRigidBodyIndex(ptr);
}

int NeoPhysics::CreateHingeJoint(int rigidbody1, int rigidbody2,
		irr::core::vector3df pivot1, irr::core::vector3df pivot2,
		irr::core::vector3df axisIn1, irr::core::vector3df axisIn2)
{
	btRigidBody*bodyA = getRigidBody(rigidbody1).get();
	btRigidBody*bodyB = getRigidBody(rigidbody2).get();
	if (!bodyA || !bodyB)
		return -1;
	btHingeConstraint* hinge = new btHingeConstraint(*bodyA, *bodyB,
			irrToBulletVector(pivot1), irrToBulletVector(pivot2),
			irrToBulletVector(axisIn1), irrToBulletVector(axisIn2));
	std::shared_ptr<btTypedConstraint> ptr(hinge);
	return assignConstraintIndex(ptr);
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

void NeoPhysics::HingeSetLimit(int hingeindex, float low, float high,
		float softness, float _biasFactor, float relaxationFactor)
{
	btHingeConstraint* hinge = static_cast<btHingeConstraint*>(getConstraint(
			hingeindex).get());
	if (hinge)
		hinge->setLimit(low, high, softness, _biasFactor, relaxationFactor);
}

void NeoPhysics::HingeEnableMotor(int hingeindex, bool enableMotor)
{
	btHingeConstraint* hinge = static_cast<btHingeConstraint*>(getConstraint(
			hingeindex).get());
	if (hinge)
		hinge->enableMotor(enableMotor);
}

void NeoPhysics::HingeEnablevoidAngularMotor(int hingeindex, bool enableMotor,
		float targetVelocity, float maxMotorImpulse)
{
	btHingeConstraint* hinge = static_cast<btHingeConstraint*>(getConstraint(
			hingeindex).get());
	if (hinge)
		hinge->enableAngularMotor(enableMotor, targetVelocity, maxMotorImpulse);
}

void NeoPhysics::PreProcessingCall()
{
}

void NeoPhysics::PostProcessingCall()
{
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

int NeoPhysics::CreateGhostObject(int collisionSahpIndex,
		std::function<void(int, btAlignedObjectArray<btCollisionObject*>&)> callback,
		irr::core::vector3df pos, irr::core::vector3df rotation)
{
	btGhostObject* go = new btGhostObject();
	go->setCollisionShape(m_collisionShapes[collisionSahpIndex].get());
	//set transform
	irr::core::matrix4 mat;
	mat.makeIdentity();
	mat.setTranslation(pos);
	mat.setRotationDegrees(rotation);
	btTransform btTrans;
	IrrlichtMatrixTobtTransform(mat, btTrans);
	go->setWorldTransform(btTrans);
	m_dynamicsWorld->addCollisionObject(go);
	std::shared_ptr<btGhostObject> ptr(go);
	return assignGhostBodyIndex(ptr, callback);
}

int NeoPhysics::assignGhostBodyIndex(std::shared_ptr<btGhostObject>& ptr,
		std::function<void(int, btAlignedObjectArray<btCollisionObject*>&)> callback)
{
	if (m_available_ghostObjects.empty())
	{
		m_ghostObjects.push_back(ptr);
		m_ghostObjectCallbacks.push_back(callback);
		return m_ghostObjects.size() - 1;
	}
	else
	{
		int index = m_available_ghostObjects.front();
		m_available_ghostObjects.pop_front();
		m_ghostObjects[index] = ptr;
		m_ghostObjectCallbacks[index] = callback;
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
		std::function<void(int, btAlignedObjectArray<btCollisionObject*>&)> callback)
{
	int colshape = CreateSphereShape(radius);
	CreateGhostObject(colshape, callback, pos);
	m_temporaryCollisionShaps.push_back(colshape);
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
