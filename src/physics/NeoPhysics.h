/*
 * NeoPhysics.h
 *
 *  Created on: 2016年2月15日
 *      Author: neo
 */

#ifndef SRC_PHYSICS_NEOPHYSICS_H_
#define SRC_PHYSICS_NEOPHYSICS_H_
#include "../game/stdafx.h"
#include <vector>
#include <set>
#include <list>
#include <map>
#include <functional>
#include "NeoMotionState.h"
#include "ExplosionPhysics.h"
#include "bulletWrapper/RigidBody.h"
#include "bulletWrapper/HingeJoint.h"
#include "bulletWrapper/Ragdoll.h"
/*
 *物理系统封装类
 */
class NeoMotionState;
class GameObject;
class ExplosionPhysics;
class NeoData;
class RigidBody;
class HingeJoint;
class Ragdoll;

using namespace std;

class NeoPhysics
{
public:
	static NeoPhysics*getInstance();
	static void Destroy();
	void Init();
	void Update(float timestep);
	void CleanUp();
	//=======creation wrapper=====
	//-------collision shapes-----
	int CreateSphereShape(float radius, const irr::core::vector3df& scale =
			irr::core::vector3df(1, 1, 1));
	int CreateBoxShape(irr::core::vector3df&size,
			const irr::core::vector3df& scale = irr::core::vector3df(1, 1, 1));
	int CreateCylinderShape(irr::core::vector3df&extents, char align = 'Y',
			const irr::core::vector3df& scale = irr::core::vector3df(1, 1, 1));
	int CreateCapsuleShape(float radius, float height, char align = 'Y',
			const irr::core::vector3df& scale = irr::core::vector3df(1, 1, 1));
	int CreateConeShape(float radius, float height, char align = 'Y',
			const irr::core::vector3df& scale = irr::core::vector3df(1, 1, 1));
	int CreateMultiSphereShape(irr::core::vector3df positions[],
			float radiuses[], int numSpheres);
	int CreateConvexHullShape(irr::scene::IMesh*mesh,
			irr::core::vector3df scale = irr::core::vector3df(1, 1, 1));
	int CreateConvexTriangleMeshShape(irr::scene::IMesh*mesh,
			irr::core::vector3df scale = irr::core::vector3df(1, 1, 1));
	int CreateBvhTriangleShape(irr::scene::IMesh*mesh,
			irr::core::vector3df scale = irr::core::vector3df(1, 1, 1));
	//int CreateHeightfieldTerrainShape(int meshIndex);
	//int CreateStaticPlaneShape();
	int CreateCompoundShape();
	void CompoundShapeAddChild(int shapeIndex, int childIndex,
			irr::core::vector3df localPos = irr::core::vector3df(0, 0, 0),
			irr::core::vector3df localRotation = irr::core::vector3df(0, 0, 0));
	void RemoveCollisionShape(int index);
	//------rigid body-------
	RigidBody* CreateRigidBody(int collisionShapeIndex,
			irr::scene::ISceneNode*node, float mass, irr::core::vector3df pos =
					irr::core::vector3df(0, 0, 0),
			irr::core::vector3df rotation = irr::core::vector3df(0, 0, 0));
	std::shared_ptr<btRigidBody> CreateRigidBody_cpp_api(int collisionShapeIndex,
			irr::scene::ISceneNode*node, float mass, irr::core::vector3df pos =
					irr::core::vector3df(0, 0, 0),
			irr::core::vector3df rotation = irr::core::vector3df(0, 0, 0));
	void RemoveRigidBody(int index);
	//------joint-------
	HingeJoint* CreateHingeJoint(RigidBody* rigidbody1, RigidBody* rigidbody2,
			irr::core::vector3df pivot1, irr::core::vector3df pivot2,
			irr::core::vector3df axisIn1, irr::core::vector3df axisIn2);
	HingeJoint* CreateHingeJoint(RigidBody*body, irr::core::vector3df pivot,
			irr::core::vector3df axis);
	std::shared_ptr<btTypedConstraint> CreateHingeJoint_cpp_api(shared_ptr<btRigidBody> rigidbody1, shared_ptr<btRigidBody> rigidbody2,
			irr::core::vector3df pivot1, irr::core::vector3df pivot2,
			irr::core::vector3df axisIn1, irr::core::vector3df axisIn2);
	std::shared_ptr<btTypedConstraint> CreateHingeJoint_cpp_api(
			shared_ptr<btRigidBody> body, irr::core::vector3df pivot,
			irr::core::vector3df axis);
	void RemoveJoint(int index);
	//------ghost object-------
	int CreateGhostObject(int collisionSahpIndex,
			std::function<void(int, btAlignedObjectArray<btCollisionObject*>&)> callback,
			irr::core::vector3df pos = irr::core::vector3df(0, 0, 0),
			irr::core::vector3df rotation = irr::core::vector3df(0, 0, 0));
	void RemoveGhostObject(int index);
	//-----explosion physics---
	std::shared_ptr<ExplosionPhysics> CreateExplosion(std::string type,
			NeoData&params);
	void RegisterExplosionCreator(std::string type,
			std::function<std::shared_ptr<ExplosionPhysics>(NeoData&)> functor);
	//---------------useful functions---------
	void GetObjectsInArea(float radius, irr::core::vector3df pos,
			std::function<void(int, btAlignedObjectArray<btCollisionObject*>&)> callback);
//	void RegisterPreProcessingCall();
//	void RemovePreProcessingCall();
//
//	void RegisterPostProcessingCall();
//	void RemovePostProcessingCall();
	//=========================
	const btBroadphaseInterface* getBroadphase();
	void setBroadphase(btBroadphaseInterface* broadphase);
	const btDefaultCollisionConfiguration* getCollisionConfiguration();
	void setCollisionConfiguration(
			btDefaultCollisionConfiguration* collisionConfiguration);
	const btCollisionDispatcher* getDispatcher();
	void setDispatcher(btCollisionDispatcher* dispatcher);
	const btDiscreteDynamicsWorld* getDynamicsWorld();
	void setDynamicsWorld(btDiscreteDynamicsWorld* dynamicsWorld);
	const btConstraintSolver* getSolver();
	void setSolver(btConstraintSolver* solver);
	int getTimescale() const;
	void setTimescale(float timescale);
	float getWorldScale() const;
	void setWorldScale(float worldScale);

	std::shared_ptr<btCollisionShape> getCollisionShape(int index);
	std::shared_ptr<btRigidBody> getRigidBody(int index);
	std::shared_ptr<btTypedConstraint> getConstraint(int index);
	static btQuaternion irrToBulletQuaternion(irr::core::quaternion&q)
	{
		return btQuaternion(q.X, q.Y, q.Z, q.W);
	}
	static btQuaternion irrToBulletQuaternion(const irr::core::quaternion&q)
	{
		return btQuaternion(q.X, q.Y, q.Z, q.W);
	}
	static irr::core::quaternion bulletToIrrQuaternion(btQuaternion&q)
	{
		return irr::core::quaternion(q.x(), q.y(), q.z(), q.w());
	}
	static irr::core::quaternion bulletToIrrQuaternion(const btQuaternion&q)
	{
		return irr::core::quaternion(q.x(), q.y(), q.z(), q.w());
	}
	static btVector3 irrToBulletVector(irr::core::vector3df&vec)
	{
		return btVector3(vec.X, vec.Y, vec.Z);
	}
	static irr::core::vector3df bulletToIrrVector(btVector3&vec)
	{
		return irr::core::vector3df(vec.x(), vec.y(), vec.z());
	}
	static btVector3 irrToBulletVector(const irr::core::vector3df&vec)
	{
		return btVector3(vec.X, vec.Y, vec.Z);
	}
	static irr::core::vector3df bulletToIrrVector(const btVector3&vec)
	{
		return irr::core::vector3df(vec.x(), vec.y(), vec.z());
	}
	static void btTransformToIrrlichtMatrix(const btTransform& worldTrans,
			irr::core::matrix4& matr)
	{
		worldTrans.getOpenGLMatrix(matr.pointer());
	}

	static void IrrlichtMatrixTobtTransform(const irr::core::matrix4& irrmat,
			btTransform& transform)
	{
		transform.setIdentity();
		transform.setFromOpenGLMatrix(irrmat.pointer());
	}

	void PreProcessingCall();
	void PostProcessingCall();
private:
	NeoPhysics();
	virtual ~NeoPhysics();
	int assignShapeIndex(std::shared_ptr<btCollisionShape>&ptr);
	int assignRigidBodyIndex(std::shared_ptr<btRigidBody>&ptr);
	int assignConstraintIndex(std::shared_ptr<btTypedConstraint>&ptr);
	int assignGhostBodyIndex(std::shared_ptr<btGhostObject>&ptr,
			std::function<void(int, btAlignedObjectArray<btCollisionObject*>&)> callback);
	btTriangleMesh*createTriangleMesh(irr::scene::IMesh*mesh,
			irr::core::vector3df scale = irr::core::vector3df(1, 1, 1),
			int*assignedIndex = NULL);
	std::shared_ptr<btTriangleMesh> getTriangleMesh(int index);
	static NeoPhysics*_instance;
	std::vector<std::shared_ptr<btCollisionShape>> m_collisionShapes;
	std::vector<std::shared_ptr<btRigidBody>> m_rigidBodies;
	std::vector<std::shared_ptr<btTriangleMesh>> m_triangleMeshes;
	std::set<std::shared_ptr<NeoMotionState>> m_motionStates;
	std::vector<std::shared_ptr<btTypedConstraint>> m_constrains;

	std::vector<std::shared_ptr<btGhostObject>> m_ghostObjects;
	std::vector<
			std::function<void(int, btAlignedObjectArray<btCollisionObject*>&)>> m_ghostObjectCallbacks;
	std::shared_ptr<btGhostPairCallback> m_ghostpairCallback;

	std::list<int> m_available_shapes;
	std::list<int> m_available_rigidbody;
	std::list<int> m_available_ghostObjects;
	std::list<int> m_available_Constraints;
	btBroadphaseInterface* m_broadphase;
	btCollisionDispatcher* m_dispatcher;
	btConstraintSolver* m_solver;
	btDefaultCollisionConfiguration* m_collisionConfiguration;
	btDiscreteDynamicsWorld* m_dynamicsWorld;
	//----------------------------------------------------------------//
	float fTimeScale;
	float fWorldScale;
	//-------------runtime structure---------//
	std::set<std::pair<GameObject*, GameObject*>> m_contact;
	std::vector<int> m_temporaryCollisionShaps;
	//-----Internal functions-----//
	std::map<std::string,
			std::function<std::shared_ptr<ExplosionPhysics>(NeoData&)>> d_explosion_type;
};

#endif /* SRC_PHYSICS_NEOPHYSICS_H_ */
