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
#ifndef HPL_AI_NODE_GENERATOR_H
#define HPL_AI_NODE_GENERATOR_H

#include "system/SystemTypes.h"
#include "game/GameTypes.h"

#include "physics/PhysicsWorld.h"
#include "scene/World3D.h"

namespace hpl {

	class cWorld3D;

	//-------------------------------

	class cAINodeGeneratorParams
	{
	public:
		cAINodeGeneratorParams();

		tString msNodeType;

		float mfHeightFromGround;
		float mfMinWallDist;

		cVector3f mvMinPos;
		cVector3f mvMaxPos;

		float mfGridSize;
	};

	//-------------------------------

	class cAINodeGenerator : public iPhysicsRayCallback
	{
	public:
		cAINodeGenerator();
		~cAINodeGenerator();

		void Generate(cWorld3D* apWorld,cAINodeGeneratorParams *apParams);

	private:
		bool OnIntersect(iPhysicsBody *pBody,cPhysicsRayParams *apParams);

		void SaveToFile();
		void LoadFromFile();

		cAINodeGeneratorParams *mpParams;
		cWorld3D* mpWorld;
		tTempAiNodeList *mpNodeList;
	};

};
#endif // HPL_AI_NODE_GENERATOR_H
