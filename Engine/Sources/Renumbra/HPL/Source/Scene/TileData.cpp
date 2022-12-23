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
#include "scene/TileData.h"


namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cTileDataNormal::cTileDataNormal(cImageManager* apImageManager, cVector2f avTileSize)

	{
		mpImageManager = apImageManager;

		mvImage.resize(eMaterialTexture_LastEnum);
		mvImage.assign(mvImage.size(), NULL);

		mvTileSize = avTileSize;
		mCollisionType = eTileCollisionType_Normal;

		mpMaterial=NULL;
		mpMesh=NULL;
		mpCollideMesh=NULL;
	}

	//-----------------------------------------------------------------------

	cTileDataNormal::~cTileDataNormal()
	{

	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	tVertexVec* cTileDataNormal::GetVertexVec(eTileRotation aRotation)
	{
		return mvVtx[aRotation];
	}
	//-----------------------------------------------------------------------

	tUIntVec* cTileDataNormal::GetIndexVec(eTileRotation aRotation)
	{
		return mvIdx;
	}

	//-----------------------------------------------------------------------

	tVertexVec* cTileDataNormal::GetCollideVertexVec(eTileRotation aRotation)
	{
		return mvCollideVtx[aRotation];
	}

	//-----------------------------------------------------------------------

	tUIntVec* cTileDataNormal::GetCollideIndexVec(eTileRotation aRotation)
	{
		return mvCollideIdx;
	}

	//-----------------------------------------------------------------------

	void cTileDataNormal::Destroy()
	{
		if(mpMaterial)hplDelete(mpMaterial);
		if(mpMesh)hplDelete(mpMesh);
		if(mpCollideMesh)hplDelete(mpCollideMesh);
	}

	//-----------------------------------------------------------------------

	void cTileDataNormal::SetData(cMesh2D *apMesh, iMaterial* apMaterial)
	{
		SetMaterial(apMaterial);
		SetMesh(apMesh); //Note that material must be set before mesh.
	}
	//-----------------------------------------------------------------------

	cMesh2D* cTileDataNormal::GetCollideMesh()
	{
		//if(mpCollideMesh==NULL) return mpMesh;

		return mpCollideMesh;
	}

	//-----------------------------------------------------------------------

	void  cTileDataNormal::SetCollideMesh(cMesh2D *apCollideMesh)
	{
		mpCollideMesh = apCollideMesh;

		for(int i=0;i<eTileRotation_LastEnum;i++)
		{
			mvCollideVtx[i] = mpCollideMesh->GetVertexVec(cRect2f(0,0,1,1),mvTileSize,(eTileRotation)i);
		}

		mvCollideIdx = mpCollideMesh->GetIndexVec();
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	void cTileDataNormal::SetMesh(cMesh2D *apMesh){
		mpMesh = apMesh;

		mpMesh->CreateTileVertexVec();

		if(mpMaterial)
		{
			cRect2f ImageRect = mpMaterial->GetTextureOffset(eMaterialTexture_Diffuse);

			for(int i=0;i<eTileRotation_LastEnum;i++)
			{
				mvVtx[i] = mpMesh->GetVertexVec(ImageRect,mvTileSize,(eTileRotation)i);
			}

			mvIdx = mpMesh->GetIndexVec();
		}
	}

	//-----------------------------------------------------------------------

	void cTileDataNormal::SetMaterial(iMaterial *apMaterial)
	{
		mpMaterial = apMaterial;
	}

	//-----------------------------------------------------------------------

}
