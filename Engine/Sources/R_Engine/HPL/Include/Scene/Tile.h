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
#ifndef HPL_TILE_H
#define HPL_TILE_H

#include <list>
#include "graphics/GraphicsTypes.h"
#include "math/MathTypes.h"
#include "system/SystemTypes.h"
#include "scene/TileData.h"

namespace hpl {

	#define eTileFlag_Breakable (eFlagBit_0)

	class cTile
	{
	public:
		cTile(iTileData* apTileData, eTileRotation aAngle,
			const cVector3f &avPos, const cVector2f &avSize, cCollisionMesh2D* apCollMesh);
		~cTile();

		iTileData* GetTileData(){ return mpTileData; }
		void SetTileData(iTileData* apTileData){mpTileData=apTileData;}

		eTileRotation GetAngle(){ return mAngle; }

		void SetTile(iTileData* apTileData, eTileRotation aAngle,
			const cVector3f &avPos, const cVector2f &avSize);
		void SetAngle(eTileRotation aAngle){ mAngle = aAngle;}

		const cVector3f& GetPosition()const{ return mvPosition;}
		cVector3f* GetPositionPtr(){ return &mvPosition;}

		cCollisionMesh2D* GetCollisionMesh(){ return mpCollMesh;}
		void SetCollisionMesh(cCollisionMesh2D* apMesh){ mpCollMesh = apMesh;}

		tFlag GetFlags(){return mlFlags;}
		void SetFlags(tFlag alFlags){ mlFlags = alFlags;}

	private:
		cCollisionMesh2D* mpCollMesh;

		tFlag mlFlags;
		iTileData* mpTileData;
		cVector3f mvPosition;
		eTileRotation mAngle; //0:normal.  1:90 CW.  2:180. CW  3:270 CW.
							//4: flip horisontally.  5: flip vertically.  6: flip both.
	};

	typedef std::list<cTile*> tTileList;
	typedef tTileList::iterator tTileListIt;
};
#endif // HPL_TILE_H
