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
#ifndef HPL_MESH_LOADER_HANDLER_H
#define HPL_MESH_LOADER_HANDLER_H

#include <list>

#include "math/MathTypes.h"
#include "graphics/GraphicsTypes.h"
#include "system/SystemTypes.h"

#include "resources/MeshLoader.h"

namespace hpl {

	class cMesh;
	class iMeshLoader;
	class cResources;
	class cWorld3D;
	class cScene;
	class cAnimation;

	typedef std::list<iMeshLoader*> tMeshLoaderList;
	typedef tMeshLoaderList::iterator tMeshLoaderListIt;

	class cMeshLoaderHandler
	{
	public:
		cMeshLoaderHandler(cResources* apResources, cScene *apScene);
		~cMeshLoaderHandler();

		cMesh* LoadMesh(const tString& asFile,tMeshLoadFlag aFlags);
		bool SaveMesh(cMesh* apMesh,const tString& asFile);

		cWorld3D* LoadWorld(const tString& asFile, tWorldLoadFlag aFlags);

		cAnimation *LoadAnimation(const tString& asFile);

		void AddLoader(iMeshLoader *apLoader);

		tStringVec* GetSupportedTypes(){ return &mvSupportedTypes;}

	private:
		tStringVec mvSupportedTypes;

		tMeshLoaderList mlstLoaders;

		cResources* mpResources;
		cScene* mpScene;
	};

};
#endif // HPL_MESH_LOADER_HANDLER_H
