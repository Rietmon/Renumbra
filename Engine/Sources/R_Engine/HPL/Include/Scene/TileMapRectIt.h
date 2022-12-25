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
#ifndef HPL_TILEMAP_RECT_IT_H
#define HPL_TILEMAP_RECT_IT_H

#include "scene/TileMapIt.h"
#include "scene/TileMap.h"
#include "math/MathTypes.h"

namespace hpl {

	class cTileMapRectIt : public iTileMapIt
	{
	public:
		/**
		 *
		 * \param avPos
		 * \param avSize
		 * \param apTileMap
		 * \param alLayer The layer that is to be iterated. -1 = All layers (hiding tiles behind solid ones)
		 * \return
		 */
		cTileMapRectIt(cVector2l avPos, cVector2l avSize, cTileMap* apTileMap, int alLayer);
		~cTileMapRectIt();

		bool HasNext();
		cTile* Next();
		cTile* PeekNext();
		int GetNum();
		int GetCurrentLayer();

	private:
		cVector2l mvPos;
		cVector2l mvSize;
		int mlLayer;
		int mlLayerCount;
		int mlTileNum;
		int mlTileColAdd;
		int mlTileRowCount;
		int mlTileColCount;

		int mlCurrentLayer;

		bool mbUpdated;

		cTileMap* mpTileMap;
		cTile* mpTile;

		void GetTile();
	};

};
#endif // HPL_TILEMAP_RECT_IT_H
