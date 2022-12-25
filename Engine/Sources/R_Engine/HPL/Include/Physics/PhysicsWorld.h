/*
 * Copyright (C) 2006-2010 - Frictional Games
 *
 * This file is part of HPL1 Engine.
 *
 * HPL1 Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HPL1 Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HPL1 Engine.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HPL_PHYSICS_WORLD_H
#define HPL_PHYSICS_WORLD_H

#include <map>
#include "system/SystemTypes.h"
#include "math/MathTypes.h"
#include "graphics/GraphicsTypes.h"

#include "physics/CollideData.h"

#include "game/SaveGame.h"

namespace hpl {

	class iCollideShape;
	class iVertexBuffer;
	class iPhysicsBody;
	class iLowLevelGraphics;
	class iPhysicsMaterial;
	class iCharacterBody;
	class iPhysicsJoint;
	class iPhysicsJointBall;
	class iPhysicsJointHinge;
	class iPhysicsJointScrew;
	class iPhysicsJointSlider;
	class iPhysicsController;
	class cWorld3D;
	class cBoundingVolume;

	typedef std::list<iCollideShape*> tCollideShapeList;
	typedef tCollideShapeList::iterator tCollideShapeListIt;

	typedef std::vector<iCollideShape*> tCollideShapeVec;
	typedef tCollideShapeVec::iterator tCollideShapeVecIt;

	typedef std::list<iPhysicsBody*> tPhysicsBodyList;
	typedef tPhysicsBodyList::iterator tPhysicsBodyListIt;

	typedef std::list<iPhysicsJoint*> tPhysicsJointList;
	typedef tPhysicsJointList::iterator tPhysicsJointListIt;

	typedef std::list<iPhysicsController*> tPhysicsControllerList;
	typedef tPhysicsControllerList::iterator tPhysicsControllerListIt;

	typedef std::list<iCharacterBody*> tCharacterBodyList;
	typedef tCharacterBodyList::iterator tCharacterBodyListIt;


	typedef std::map<tString, iPhysicsMaterial*> tPhysicsMaterialMap;
	typedef tPhysicsMaterialMap::iterator tPhysicsMaterialMapIt;

	typedef cSTLMapIterator<iPhysicsMaterial*, tPhysicsMaterialMap, tPhysicsMaterialMapIt> cPhysicsMaterialIterator;

	typedef cSTLIterator<iPhysicsBody*, tPhysicsBodyList, tPhysicsBodyListIt> cPhysicsBodyIterator;
	typedef cSTLIterator<iPhysicsJoint*, tPhysicsJointList, tPhysicsJointListIt> cPhysicsJointIterator;

	enum ePhysicsAccuracy
	{
		ePhysicsAccuracy_Low,
		ePhysicsAccuracy_Medium,
		ePhysicsAccuracy_High,
		ePhysicsAccuracy_LastEnum
	};

	//----------------------------------------------------

	class cPhysicsRayParams
	{
	public:
		float mfT;
		float mfDist;
		cVector3f mvNormal;
		cVector3f mvPoint;
	};

	class iPhysicsRayCallback
	{
	public:
		virtual bool BeforeIntersect(iPhysicsBody *pBody){return true;}
		virtual bool OnIntersect(iPhysicsBody *pBody,cPhysicsRayParams *apParams)=0;
	};

	class iPhysicsWorldCollisionCallback
	{
	public:
		virtual void OnCollision(iPhysicsBody *apBody, cCollideData *apCollideData)=0;
	};

	//----------------------------------------------------

	class iPhysicsWorld
	{
	public:
		iPhysicsWorld();
		virtual ~iPhysicsWorld();

		//########################################################################################
		//! \name General
		//########################################################################################
		//! @{

		void Update(float afTimeStep);
		virtual void Simulate(float afTimeStep)=0;

		virtual void  SetMaxTimeStep(float afTimeStep)=0;
		virtual float GetMaxTimeStep()=0;

		virtual void SetWorldSize(const cVector3f &avMin,const cVector3f &avMax)=0;
		virtual cVector3f GetWorldSizeMin()=0;
		virtual cVector3f GetWorldSizeMax()=0;

		virtual void SetGravity(const cVector3f& avGravity)=0;
		virtual cVector3f GetGravity()=0;

		virtual void SetAccuracyLevel(ePhysicsAccuracy aAccuracy)=0;
		virtual ePhysicsAccuracy GetAccuracyLevel()=0;
		//! @}

		//########################################################################################
		//! \name Shapes
		//########################################################################################
		//! @{

		virtual iCollideShape* CreateNullShape()=0;
		virtual iCollideShape* CreateBoxShape(const cVector3f &avSize, cMatrixf* apOffsetMtx)=0;
		virtual iCollideShape* CreateSphereShape(const cVector3f &avRadii, cMatrixf* apOffsetMtx)=0;
		virtual iCollideShape* CreateCylinderShape(float afRadius, float afHeight, cMatrixf* apOffsetMtx)=0;
		virtual iCollideShape* CreateCapsuleShape(float afRadius, float afHeight, cMatrixf* apOffsetMtx)=0;
		virtual iCollideShape* CreateMeshShape(iVertexBuffer *apVtxBuffer)=0;
		virtual iCollideShape* CreateCompundShape(tCollideShapeVec &avShapes)=0;
		void DestroyShape(iCollideShape *apShape);

		//! @}

		//########################################################################################
		//! \name Joints
		//########################################################################################
		//! @{

		virtual iPhysicsJointBall* CreateJointBall(const tString &asName,
											const cVector3f& avPivotPoint,
											iPhysicsBody* apParentBody, iPhysicsBody *apChildBody)=0;
		virtual iPhysicsJointHinge* CreateJointHinge(const tString &asName,
											const cVector3f& avPivotPoint,const cVector3f& avPinDir,
											iPhysicsBody* apParentBody, iPhysicsBody *apChildBody)=0;
		virtual iPhysicsJointSlider* CreateJointSlider(const tString &asName,
											const cVector3f& avPivotPoint,const cVector3f& avPinDir,
											iPhysicsBody* apParentBody, iPhysicsBody *apChildBody)=0;
		virtual iPhysicsJointScrew* CreateJointScrew(const tString &asName,
											const cVector3f& avPivotPoint,const cVector3f& avPinDir,
											iPhysicsBody* apParentBody, iPhysicsBody *apChildBody)=0;
		void DestroyJoint(iPhysicsJoint* apJoint);
		iPhysicsJoint *GetJoint(const tString &asName);
		cPhysicsJointIterator GetJointIterator();

		//! @}

		//########################################################################################
		//! \name Materials
		//########################################################################################
		//! @{

		virtual iPhysicsMaterial* CreateMaterial(const tString &asName)=0;
		iPhysicsMaterial* GetMaterialFromName(const tString &asName);
		cPhysicsMaterialIterator GetMaterialIterator();

		//! @}

		//########################################################################################
		//! \name Bodies
		//########################################################################################
		//! @{

		virtual iPhysicsBody* CreateBody(const tString &asName,iCollideShape *apShape)=0;
		void DestroyBody(iPhysicsBody* apBody);
		iPhysicsBody *GetBody(const tString &asName);
		cPhysicsBodyIterator GetBodyIterator();

		virtual iCharacterBody *CreateCharacterBody(const tString &asName, const cVector3f &avSize)=0;
		void DestroyCharacterBody(iCharacterBody* apBody);
		iPhysicsBody *GetCharacterBody(const tString &asName);

		void GetBodiesInBV(cBoundingVolume *apBV, tPhysicsBodyList *apBodyList);
		void EnableBodiesInBV(cBoundingVolume *apBV, bool abEnabled);


		//! @}


		//########################################################################################
		//! \name Tools
		//########################################################################################
		//! @{

		void SetLogDebug(bool abX){ mbLogDebug = abX;}
		bool GetLogDebug(){ return mbLogDebug;}

		void AddSaveData(cSaveDataHandler* apHandler);

		virtual iPhysicsController *CreateController(const tString &asName)=0;
		void DestroyController(iPhysicsController *apController);

		tCollidePointVec* GetContactPoints(){ return &mvContactPoints;}
		void SetSaveContactPoints(bool abX){ mbSaveContactPoints = abX;}
		bool GetSaveContactPoints(){ return mbSaveContactPoints;}
		void RenderContactPoints(iLowLevelGraphics *apLowLevel, const cColor& aPointColor,
								const cColor& aLineColor);

		virtual void CastRay(iPhysicsRayCallback *apCallback,
							const cVector3f &avOrigin, const cVector3f& avEnd,
							bool abCalcDist, bool abCalcNormal, bool abCalcPoint,
							bool abUsePrefilter=false)=0;

		virtual void RenderDebugGeometry(iLowLevelGraphics *apLowLevel, const cColor& aColor)=0;

		virtual bool CheckShapeCollision(	iCollideShape* apShapeA, const cMatrixf& a_mtxA,
										iCollideShape* apShapeB, const cMatrixf& a_mtxB,
										cCollideData & aCollideData, int alMaxPoints=4)=0;

		bool CheckShapeWorldCollision(cVector3f *apNewPos,
										iCollideShape* apShape, const cMatrixf& a_mtxTransform,
										iPhysicsBody *apSkipBody=NULL, bool abSkipStatic=false,
										bool abIsCharacter=false,
										iPhysicsWorldCollisionCallback *apCallback=NULL,
										bool abCollideCharacter=true,
										bool abDebug=false);

		void DestroyAll();

		cWorld3D* GetWorld3D(){ return mpWorld3D;}
		void SetWorld3D(cWorld3D *apWorld3D){ mpWorld3D = apWorld3D;}
		//! @}

	protected:
		tCollideShapeList mlstShapes;
		tPhysicsBodyList mlstBodies;
		tCharacterBodyList mlstCharBodies;
		tPhysicsMaterialMap m_mapMaterials;
		tPhysicsJointList mlstJoints;
		tPhysicsControllerList mlstControllers;
		cWorld3D *mpWorld3D;

		bool mbLogDebug;

		tCollidePointVec mvContactPoints;
		bool mbSaveContactPoints;
	};
};
#endif // HPL_PHYSICS_WORLD_H

