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
#include "scene/Light2D.h"

#include "scene/GridMap2D.h"
#include "graphics/LowLevelGraphics.h"


namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	iLight2D::iLight2D(tString asName) : iEntity2D(asName) , iLight()
	{

	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	void iLight2D::SetFarAttenuation(float afX)
	{
		mfFarAttenuation = afX;
		if(UpdateBoundingBox())
			if(mpGridObject)
				mpGridObject->Update(GetBoundingBox());
	}
	//-----------------------------------------------------------------------

	void iLight2D::SetNearAttenuation(float afX)
	{
		mfNearAttenuation = afX;
		if(mfNearAttenuation>mfFarAttenuation)
			SetFarAttenuation(mfNearAttenuation);
	}
	//-----------------------------------------------------------------------

	cVector3f iLight2D::GetLightPosition()
	{
		return GetWorldPosition();
	}

	//-----------------------------------------------------------------------

	void iLight2D::UpdateLogic(float afTimeStep)
	{
		UpdateLight(afTimeStep);
		if(mfFadeTime>0)
		{
			if(UpdateBoundingBox())
				mpGridObject->Update(mBoundingBox);
		}
	}


	//-----------------------------------------------------------------------

}
