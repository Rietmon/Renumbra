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
#include "graphics/Animation.h"

#include "math/Math.h"
#include "graphics/AnimationTrack.h"

namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cAnimation::cAnimation(const tString &asName, const tString &asFile) : iResourceBase(asName,0)
	{
		msAnimName = "";
		msFileName = asFile;
	}

	//-----------------------------------------------------------------------

	cAnimation::~cAnimation()
	{
		STLDeleteAll(mvTracks);
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	float cAnimation::GetLength()
	{
		return mfLength;
	}

	//-----------------------------------------------------------------------

	void cAnimation::SetLength(float afTime)
	{
		mfLength = afTime;
	}

	//-----------------------------------------------------------------------

	cAnimationTrack* cAnimation::CreateTrack(const tString &asName, tAnimTransformFlag aFlags)
	{
		cAnimationTrack *pTrack = hplNew( cAnimationTrack,(asName, aFlags, this) );

		mvTracks.push_back(pTrack);

		return pTrack;
	}

	//-----------------------------------------------------------------------

	cAnimationTrack* cAnimation::GetTrack(int alIndex)
	{
		return mvTracks[alIndex];
	}

	//-----------------------------------------------------------------------

	cAnimationTrack* cAnimation::GetTrackByName(const tString &asName)
	{
		for(size_t i=0; i< mvTracks.size(); ++i)
		{
			if(asName == tString(mvTracks[i]->GetName()))
			{
				return mvTracks[i];
			}
		}

		return NULL;
	}

	//-----------------------------------------------------------------------

	void cAnimation::ResizeTracks(int alNum)
	{
		mvTracks.reserve(alNum);
	}

	//-----------------------------------------------------------------------

	int cAnimation::GetTrackNum()
	{
		return (int)mvTracks.size();
	}

	//-----------------------------------------------------------------------


	//////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	//-----------------------------------------------------------------------
}
