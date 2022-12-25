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
#include "sound/LowLevelSound.h"

#include "sound/SoundEnvironment.h"

namespace hpl {
	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	iLowLevelSound::iLowLevelSound()
	{
		mfVolume=1;
		mfEnvVolume=0;
		mbListenerAttenuation=true;
		mbHardwareAcc = false;
		mbEnvAudioEnabled = false;
	}

	//-----------------------------------------------------------------------

	iLowLevelSound::~iLowLevelSound()
	{
		STLDeleteAll(mlstSoundEnv);
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	iSoundEnvironment* iLowLevelSound::GetSoundEnvironmentFromFileName (const tString& asName)
	{
		tString sLowName = cString::ToLowerCase(asName);
		for (tSoundEnvListIt SEIt = mlstSoundEnv.begin(); SEIt != mlstSoundEnv.end(); ++SEIt)
		{
			iSoundEnvironment* pSoundEnv = *SEIt;

			if(sLowName == pSoundEnv->GetFileName()) return pSoundEnv;
		}
		return NULL;
	}

	//-----------------------------------------------------------------------

	/*void iLowLevelSound::DestroySoundEnvironment( iSoundEnvironment* apSoundEnv)
	{
		Log(" Destroy %d\n",apSoundEnv);

		STLFindAndDelete(mlstSoundEnv,apSoundEnv);
	}*/

	//-----------------------------------------------------------------------
}