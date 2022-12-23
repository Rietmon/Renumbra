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
#ifndef HPL_TILELAYER_H
#define HPL_TILELAYER_H

#include <vector>
#include "scene/Tile.h"
#include "math/MathTypes.h"
#include "system/SystemTypes.h"

namespace hpl {

	enum eTileLayerType
	{
		eTileLayerType_Normal,
		eTileLayerType_LastEnum
	};

	typedef std::vector<cTile*> tTileVec;
	typedef tTileVec::iterator tTileVecIt;

	class cTileLayer
	{
	friend class cTileMapRectIt;
	friend class cTileMapLineIt;
	public:
		cTileLayer(unsigned int alW, unsigned int alH, bool abCollision,bool abLit, eTileLayerType aType,float afZ=0);
		~cTileLayer();

		bool SetTile(unsigned int alX,unsigned int alY, cTile *aVal);
		cTile* GetAt(int alX, int alY);
		cTile* GetAt(int alNum);

		void SetZ(float afZ){mfZ = afZ;}
		float GetZ(){return mfZ;}

		bool HasCollision(){ return mbCollision;}

	private:
		tTileVec mvTile;

		cVector2l mvSize;
		bool mbCollision;
		bool mbLit;
		float mfZ;
		eTileLayerType mType;
	};

};
#endif // HPL_TILELAYER_H
