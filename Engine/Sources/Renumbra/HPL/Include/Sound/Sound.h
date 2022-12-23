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
#ifndef HPL_SOUND_H
#define HPL_SOUND_H

#include "game/Updateable.h"

namespace hpl {

	class iLowLevelSound;
	class cResources;
	class cSoundHandler;
	class cMusicHandler;

	class cSound : public iUpdateable
	{
	public:
		cSound(iLowLevelSound *apLowLevelSound);
		~cSound();

		void Init(	cResources *apResources, bool abUseHardware, bool abForceGeneric, bool abUseEnvAudio, int alMaxChannels,
						int alStreamUpdateFreq, bool abUseThreading, bool abUseVoiceManagement,
						int alMaxMonoSourceHint, int alMaxStereoSourceHint,
						int alStreamingBufferSize, int alStreamingBufferCount, bool abEnableLowLevelLog, tString asDeviceName);

		void Update(float afTimeStep);

		iLowLevelSound* GetLowLevel(){ return mpLowLevelSound;}
		cSoundHandler* GetSoundHandler(){ return mpSoundHandler; }
		cMusicHandler* GetMusicHandler(){ return mpMusicHandler; }

	private:
		iLowLevelSound *mpLowLevelSound;
		cResources* mpResources;
		cSoundHandler* mpSoundHandler;
		cMusicHandler* mpMusicHandler;
	};

};
#endif // HPL_SOUND_H
