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
#ifndef HPL_MESHCREATOR_H
#define HPL_MESHCREATOR_H

#include "math/MathTypes.h"
#include "system/SystemTypes.h"
#include "graphics/GraphicsTypes.h"

namespace hpl {

	class cMesh2D;
	class iVertexBuffer;
	class iLowLevelGraphics;
	class cResources;
	class cMesh;

	class cMeshCreator
	{
	public:
		cMeshCreator(iLowLevelGraphics *apLowLevelGraphics, cResources *apResources);
		~cMeshCreator();

		cMesh2D *Create2D(tString asName, cVector2f mvSize);

		cMesh* CreateBox(const tString &asName, cVector3f avSize, const tString &asMaterial);

		iVertexBuffer* CreateSkyBoxVertexBuffer(float afSize);
		iVertexBuffer* CreateBoxVertexBuffer(cVector3f avSize);

	private:
		cVector3f GetBoxTex(int i,int x, int y, int z, cVector3f *vAdd);
		int GetBoxIdx(int i,int x, int y, int z);

		iLowLevelGraphics *mpLowLevelGraphics;
		cResources *mpResources;
	};

};
#endif // HPL_MESHCREATOR_H


