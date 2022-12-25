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
#ifndef HPL_SCRIPT_FUNCS_H
#define HPL_SCRIPT_FUNCS_H

#include "physics/PhysicsJoint.h"

namespace hpl {

	class cGraphics;
	class cResources;
	class cSystem;
	class cSound;
	class cScene;
	class cInput;
	class cGame;



	//---------------------------------------

	class cScriptJointCallback : public iPhysicsJointCallback
	{
	public:
		cScriptJointCallback(cScene *apScene);

		void OnMinLimit(iPhysicsJoint *apJoint);
		void OnMaxLimit(iPhysicsJoint *apJoint);

		bool IsScript(){ return true;}

		tString msMaxFunc;
		tString msMinFunc;

		cScene *mpScene;
	};

	//---------------------------------------

	class cScriptFuncs
	{
	public:
		static void Init(	cGraphics* apGraphics,
					cResources *apResources,
					cSystem *apSystem,
					cInput *apInput,
					cScene *apScene,
					cSound *apSound,
					cGame *apGame
					);
	};

};
#endif // HPL_SCRIPT_FUNCS_H
