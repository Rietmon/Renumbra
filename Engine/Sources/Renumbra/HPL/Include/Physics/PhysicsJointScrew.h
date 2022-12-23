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
#ifndef HPL_PHYSICS_JOINT_SCREW_H
#define HPL_PHYSICS_JOINT_SCREW_H

#include "physics/PhysicsJoint.h"

namespace hpl {

	//-----------------------------------

	kSaveData_ChildClass(iPhysicsJoint, iPhysicsJointScrew)
	{
		kSaveData_ClassInit(iPhysicsJointScrew)
	public:
		float mfMaxDistance;
		float mfMinDistance;
		cVector3f mvPin;

		virtual iSaveObject* CreateSaveObject(cSaveObjectHandler *apSaveObjectHandler,cGame *apGame);
		virtual int GetSaveCreatePrio();
	};

	//-----------------------------------

	class iPhysicsJointScrew : public iPhysicsJoint
	{
	#ifdef __GNUC__
		typedef iPhysicsJoint __super;
	#endif
	public:
		iPhysicsJointScrew(const tString &asName, iPhysicsBody *apParentBody, iPhysicsBody *apChildBody,
			iPhysicsWorld *apWorld,const cVector3f &avPivotPoint)
			: iPhysicsJoint(asName,apParentBody,apChildBody, apWorld,avPivotPoint){}
		virtual ~iPhysicsJointScrew(){}

		/**
		* Set the maximum distance the bodies can be from each other, relative to the start dist between them
		* This is true if pin points towards the child.
		* In other words, distance increases as the distance between start pivot and current pivot
		* increases in the opposite direction of the pin.
		*/
		virtual void SetMaxDistance(float afX)=0;
		virtual void SetMinDistance(float afX)=0;
		virtual float GetMaxDistance()=0;
		virtual float GetMinDistance()=0;

		ePhysicsJointType GetType(){ return ePhysicsJointType_Screw;}

		//SaveObject implementation
		virtual iSaveData* CreateSaveData();
		virtual void SaveToSaveData(iSaveData *apSaveData);
		virtual void LoadFromSaveData(iSaveData *apSaveData);
		virtual void SaveDataSetup(cSaveObjectHandler *apSaveObjectHandler, cGame *apGame);

	protected:
		float mfMaxDistance;
		float mfMinDistance;

		cVector3f mvPin;
	};
};
#endif // HPL_PHYSICS_JOINT_SCREW_H
