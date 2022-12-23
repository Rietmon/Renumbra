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
#ifndef HPL_ENTITY_LOADER_OBJECT_H
#define HPL_ENTITY_LOADER_OBJECT_H

#include "system/SystemTypes.h"
#include "math/MathTypes.h"
#include "graphics/GraphicsTypes.h"

#include "resources/Resources.h"

class TiXmlElement;

namespace hpl {

	class iPhysicsBody;
	class iPhysicsJoint;
	class iPhysicsWorld;
	class cMesh;
	class cMeshEntity;
	class cParticleSystem3D;
	class cBillboard;
	class cBeam;
	class cSoundEntity;
	class iLight3D;
	class iHapticShape;

	class cEntityLoader_Object : public iEntity3DLoader
	{
	public:
		cEntityLoader_Object(const tString &asName) : iEntity3DLoader(asName){}
		virtual ~cEntityLoader_Object(){}

		iEntity3D* Load(const tString &asName, TiXmlElement *apRootElem, const cMatrixf &a_mtxTransform,
					cWorld3D *apWorld, const tString &asFileName, bool abLoadReferences);

	protected:
		virtual void BeforeLoad(TiXmlElement *apRootElem, const cMatrixf &a_mtxTransform,cWorld3D *apWorld){};
		virtual void AfterLoad(TiXmlElement *apRootElem, const cMatrixf &a_mtxTransform,cWorld3D *apWorld){};

		void SetBodyProperties(iPhysicsBody *apBody, TiXmlElement *apPhysicsElem);
		void SetJointProperties(iPhysicsJoint *apJoint, TiXmlElement *apJointElem,cWorld3D *apWorld);

		void LoadController(iPhysicsJoint *apJoint,iPhysicsWorld *apPhysicsWorld, TiXmlElement *apElem);

		eAnimationEventType GetAnimationEventType(const char* apString);

		tString msSubType;
		tString msName;

		tString msFileName;

		std::vector<iPhysicsBody*> mvBodies;
		std::vector<iPhysicsJoint*> mvJoints;

		std::vector<iHapticShape*> mvHapticShapes;

		std::vector<iLight3D*> mvLights;
		std::vector<cParticleSystem3D*> mvParticleSystems;
		std::vector<cBillboard*> mvBillboards;
		std::vector<cBeam*> mvBeams;
		std::vector<cSoundEntity*> mvSoundEntities;

		cMeshEntity *mpEntity;
		cMesh *mpMesh;
	};

};
#endif // HPL_ENTITY_LOADER_OBJECT_H
