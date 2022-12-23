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
#ifndef HPL_OPENAL_SOUND_CHANNEL_H
#define HPL_OPENAL_SOUND_CHANNEL_H

#include "sound/SoundChannel.h"
#include "sound/SoundData.h"

#include "OALWrapper/OAL_Funcs.h"

namespace hpl {

	class cOpenALSoundChannel : public iSoundChannel
	{
	public:
		cOpenALSoundChannel(iSoundData* apData, int alChannel, cSoundManager* apSoundManger);
		~cOpenALSoundChannel();

		void Play();
		void Stop();

		void SetPaused(bool abX);
		void SetSpeed(float afSpeed);
		void SetVolume (float afVolume);
		void SetLooping (bool abLoop);
		void SetPan (float afPan);
		void Set3D(bool ab3D);

		void SetPriority(int alX);
		int GetPriority();

		void SetPositionRelative(bool abRelative);
		void SetPosition(const cVector3f &avPos);
		void SetVelocity(const cVector3f &avVel);

		void SetMinDistance(float fMin);
		void SetMaxDistance(float fMax);

		bool IsPlaying();

		bool IsBufferUnderrun() { return OAL_Source_IsBufferUnderrun(mlChannel);}
		double GetElapsedTime()	{ return OAL_Source_GetElapsedTime(mlChannel);}
		double GetTotalTime()	{ return OAL_Source_GetTotalTime(mlChannel);}

		void SetAffectedByEnv(bool abAffected);
		void SetFiltering ( bool abEnabled, int alFlags);
		void SetFilterGain(float afGain);
		void SetFilterGainHF(float afGainHF);

	private:
		int mlChannel;
		int mlDefaultFreq;

		float mfPosition[3];
		float mfVelocity[3];
	};
};
#endif // HPL_OPENAL_CHANNEL_H
