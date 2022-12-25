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
#include "scene/ColliderEntity.h"

#include "physics/PhysicsWorld.h"
#include "physics/PhysicsBody.h"
#include "physics/CollideShape.h"

namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cColliderEntity::cColliderEntity(const tString &asName,iPhysicsBody* apBody, iPhysicsWorld *apWorld):
	iRenderable(asName)
	{
		mpPhysicsWorld = apWorld;
		mpBody = apBody;

		mBoundingVolume = apBody->GetShape()->GetBoundingVolume();
	}

	//-----------------------------------------------------------------------

	cColliderEntity::~cColliderEntity()
	{
		if(mpBody && mpPhysicsWorld)
			mpPhysicsWorld->DestroyBody(mpBody);
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cBoundingVolume* cColliderEntity::GetBoundingVolume()
	{
		return &mBoundingVolume;
	}

	//-----------------------------------------------------------------------

	cMatrixf* cColliderEntity::GetModelMatrix(cCamera3D *apCamera)
	{
		return &GetWorldMatrix();
	}

	//-----------------------------------------------------------------------

	int cColliderEntity::GetMatrixUpdateCount()
	{
		return GetTransformUpdateCount();
	}

	//-----------------------------------------------------------------------


	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	//-----------------------------------------------------------------------
}
