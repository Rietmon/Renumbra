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
#ifndef HPL_SOUNDSOURCE_H
#define HPL_SOUNDSOURCE_H

#include <list>
#include "scene/Entity2D.h"
#include "system/SystemTypes.h"

class TiXmlElement;

namespace hpl {

	class cSound;
	class iSoundChannel;

	class cSoundSource : public iEntity2D
	{
	public:
		cSoundSource(const tString& asName,const tString& asSoundName, cSound* apSound, bool abVolatile);
		~cSoundSource();

		tString GetEntityType(){ return "SoundSource";}

		void UpdateLogic(float afTimeStep);

		bool LoadData(TiXmlElement* apRootElem);

		bool IsDead();

		void SetInterval(int alX){mlInterval = alX;}
		void SetLoop(bool abX){mbLoop = abX;}
		void SetRelative(bool abX){mbRelative = abX;}
		void SetMaxDist(float afX){mfMaxDist = afX;}
		void SetMinDist(float afX){mfMinDist = afX;}
		void SetRandom(int alX){mlRandom = alX;}
		void SetVolume(float afX){mfVolume = afX;}

		iSoundChannel* GetSoundChannel(){ return mpSoundChannel;}


		const cRect2f& GetBoundingBox();
		bool UpdateBoundingBox();

		void Stop();

	private:
		cSound* mpSound;
		bool mbVolatile;

		int mlInterval;
		bool mbLoop;
		bool mbRelative;
		float mfMaxDist;
		float mfMinDist;
		int mlRandom;
		tString msSoundName;
		float mfVolume;
		int mlCounter;

		bool mbPlaying;

		iSoundChannel *mpSoundChannel;

		void Play();
	};

	typedef std::list<cSoundSource*> tSoundSourceList;
	typedef tSoundSourceList::iterator tSoundSourceListIt;
};
#endif // HPL_SOUNDSOURCE_H
