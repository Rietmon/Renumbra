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
#ifndef HPL_SCENE_H
#define HPL_SCENE_H

#include <list>

#include "system/SystemTypes.h"
#include "game/GameTypes.h"

#include "game/Updateable.h"
#include "scene/Camera3D.h"

#include "resources/MeshLoader.h"

namespace hpl {

	class cAI;
	class cGraphics;
	class cResources;
	class cSystem;
	class cSound;
	class cPhysics;
	class cHaptic;
	class cCollider2D;
	class iCamera;
	class cCamera2D;
	class cUpdater;
	class cWorld3D;
	class cWorld2D;

	typedef std::list<iCamera*> tCameraList;
	typedef tCameraList::iterator tCameraListIt;

	typedef std::list<cWorld3D*> tWorld3DList;
	typedef tWorld3DList::iterator tWorld3DListIt;

	class cScene : public iUpdateable
	{
	public:
		cScene(cGraphics *apGraphics,cResources *apResources, cSound* apSound, cPhysics *apPhysics,
				cSystem *apSystem, cAI *apAI, cHaptic *apHaptic);
		~cScene();

		void Reset();

		/**
		* Called by cGame
		*/
		void UpdateRenderList(float afFrameTime);
		/**
		 * Called by cGame
		 */
		void Render(cUpdater* apUpdater, float afFrameTime);

		bool LoadMap2D(tString asFile);

		void RenderWorld2D(cCamera2D *apCam,cWorld2D* apWorld);

		void Update(float afTimeStep);

		void ClearLoadedMaps(){m_setLoadedMaps.clear();}
		tStringSet* GetLoadedMapsSet(){ return &m_setLoadedMaps;}

		void SetDrawScene(bool abX);
		bool GetDrawScene(){ return mbDrawScene;}

		///// SCRIPT VAR METHODS ////////////////////

		cScriptVar* CreateLocalVar(const tString& asName);
		cScriptVar* GetLocalVar(const tString& asName);
		tScriptVarMap* GetLocalVarMap();
		cScriptVar* CreateGlobalVar(const tString& asName);
		cScriptVar* GetGlobalVar(const tString& asName);
		tScriptVarMap* GetGlobalVarMap();

		///// CAMERA 2D METHODS ////////////////////


		cCamera2D* CreateCamera2D(unsigned int alW,unsigned int alH);
		cCamera3D* CreateCamera3D(eCameraMoveMode aMoveMode);

		void DestroyCamera(iCamera* apCam);

		/**
		 * This sets the current camera, depending on this one is 2D or 3D a 2D or 3D world will be rendered.
		 * \param pCam
		 */
		void SetCamera(iCamera* pCam);
		iCamera* GetCamera(){ return mpActiveCamera; }
		void SetCameraPosition(const cVector3f& avPos);
		cVector3f GetCameraPosition();

		void SetCameraIsListener(bool abX){ mbCameraIsListener = abX; }

		///// WORLD METHODS ////////////////////

		cWorld3D* LoadWorld3D(const tString& asFile, bool abLoadScript, tWorldLoadFlag aFlags);
		cWorld3D* CreateWorld3D(const tString& asName);
		void DestroyWorld3D(cWorld3D* apWorld);

		void SetWorld3D(cWorld3D* apWorld);
		cWorld3D* GetWorld3D(){ return mpCurrentWorld3D;}

		bool HasLoadedWorld(const tString &asFile);

		cWorld2D* GetWorld2D(){ return mpCurrentWorld2D;}
		cCollider2D* GetCollider2D(){return mpCollider2D;}

		void SetUpdateMap(bool abX){ mbUpdateMap = abX;}
		bool GetUpdateMap(){return mbUpdateMap;}

		cSystem* GetSystem(){ return mpSystem;}

	private:
		cGraphics *mpGraphics;
		cResources *mpResources;
		cSound *mpSound;
		cPhysics *mpPhysics;
		cSystem *mpSystem;
		cAI *mpAI;
		cHaptic *mpHaptic;

		cCollider2D *mpCollider2D;

		bool mbDrawScene;
		bool mbUpdateMap;

		tWorld3DList mlstWorld3D;
		cWorld3D* mpCurrentWorld3D;

		cWorld2D* mpCurrentWorld2D;
		tCameraList mlstCamera;
		iCamera *mpActiveCamera;
		bool mbCameraIsListener;

		tScriptVarMap m_mapLocalVars;
		tScriptVarMap m_mapGlobalVars;

		tStringSet m_setLoadedMaps;
	};

};
#endif // HPL_SCENE_H
