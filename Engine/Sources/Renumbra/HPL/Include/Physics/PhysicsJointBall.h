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
#ifndef HPL_PHYSICS_JOINT_BALL_H
#define HPL_PHYSICS_JOINT_BALL_H

#include "physics/PhysicsJoint.h"

namespace hpl {

	//-----------------------------------

	kSaveData_ChildClass(iPhysicsJoint, iPhysicsJointBall)
	{
		kSaveData_ClassInit(iPhysicsJointBall)
	public:
		float mfMaxConeAngle;
		float mfMaxTwistAngle;
		cVector3f mvConePin;

		virtual iSaveObject* CreateSaveObject(cSaveObjectHandler *apSaveObjectHandler,cGame *apGame);
		virtual int GetSaveCreatePrio();
	};

	//-----------------------------------

	class iPhysicsJointBall : public iPhysicsJoint
	{
	#ifdef __GNUC__
		typedef iPhysicsJoint __super;
	#endif
	public:
		iPhysicsJointBall(const tString &asName, iPhysicsBody *apParentBody, iPhysicsBody *apChildBody,
			iPhysicsWorld *apWorld, const cVector3f &avPivotPoint)
			: iPhysicsJoint(asName,apParentBody,apChildBody, apWorld,avPivotPoint){}
		virtual ~iPhysicsJointBall(){}

		virtual void SetConeLimits(const cVector3f& avPin, float afMaxConeAngle, float afMaxTwistAngle)=0;
		virtual cVector3f GetAngles()=0;

		float GetMaxConeAngle(){ return mfMaxConeAngle;}
		float GetMaxTwistAngle(){ return mfMaxTwistAngle;}
		cVector3f GetConePin(){ return mvConePin;}

		ePhysicsJointType GetType(){ return ePhysicsJointType_Ball;}

		//SaveObject implementation
		virtual iSaveData* CreateSaveData();
		virtual void SaveToSaveData(iSaveData *apSaveData);
		virtual void LoadFromSaveData(iSaveData *apSaveData);
		virtual void SaveDataSetup(cSaveObjectHandler *apSaveObjectHandler, cGame *apGame);

	protected:
		float mfMaxConeAngle;
		float mfMaxTwistAngle;
		cVector3f mvConePin;
	};
};
#endif // HPL_PHYSICS_JOINT_BALL_H
