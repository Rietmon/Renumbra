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
#ifndef HPL_SOUND_ENTITY_H
#define HPL_SOUND_ENTITY_H

#include "scene/Entity3D.h"
#include "sound/SoundChannel.h"

namespace hpl {

	class cSoundHandler;
	class cSoundEntityData;
	class cSoundEntityManager;
	class cWorld3D;
	class cSoundEntry;

	enum eSoundEntityType
	{
		eSoundEntityType_Main,
		eSoundEntityType_Start,
		eSoundEntityType_Stop,
		eSoundEntityType_LastEnum
	};

	class cSoundEntity;

	class cSoundEntityChannelCallback : public iSoundChannelCallback
	{
	public:
		void OnPriorityRelease();

		cSoundEntity *mpEntity;
	};

	//----------------------------------------

	kSaveData_ChildClass(iEntity3D, cSoundEntity)
	{
		kSaveData_ClassInit(cSoundEntity)
	public:
		tString msData;
		bool mbStopped;
		bool mbRemoveWhenOver;
		bool mbStarted;
		bool mbFadingOut;
		float mfVolume;

		virtual iSaveObject* CreateSaveObject(cSaveObjectHandler *apSaveObjectHandler,cGame *apGame);
		virtual int GetSaveCreatePrio();
	};

	//------------------------------------------

	class iSoundEntityGlobalCallback
	{
	public:
		virtual void OnStart(cSoundEntity *apSoundEntity)=0;
	};

	typedef std::list<iSoundEntityGlobalCallback*> tSoundEntityGlobalCallbackList;
	typedef tSoundEntityGlobalCallbackList::iterator tSoundEntityGlobalCallbackListIt;

	//------------------------------------------

	class cSoundEntity : public iEntity3D
	{
	#ifdef __GNUC__
		typedef iEntity3D __super;
	#endif
	friend class cSoundEntityChannelCallback;
	public:
		cSoundEntity(const tString& asName,cSoundEntityData *apData,
						cSoundEntityManager *apSoundEntityManager,
						cWorld3D *apWorld,
						cSoundHandler *apSoundHandler, bool abRemoveWhenOver);
		~cSoundEntity();

		void Play(bool abPlayStart=true);
		void Stop(bool abPlayEnd=true);

		void FadeIn(float afSpeed);
		void FadeOut(float afSpeed);

		bool IsStopped();
		bool IsFadingOut();
		bool GetRemoveWhenOver();

		void SetVolume(float afX){ mfVolume = afX;}
		float GetVolume(){ return mfVolume;}

		iSoundChannel* GetSound(eSoundEntityType aType){ return mvSounds[aType];}
		cSoundEntry* GetSoundEntry(eSoundEntityType aType);

		//Entity implementation
		void UpdateLogic(float afTimeStep);

		tString GetEntityType(){ return "SoundEntity";}

		cSoundEntityData* GetData(){ return mpData;}

		static void AddGlobalCallback(iSoundEntityGlobalCallback *apCallback);
		static void RemoveGlobalCallback(iSoundEntityGlobalCallback *apCallback);


		//SaveObject implementation
		virtual iSaveData* CreateSaveData();
		virtual void SaveToSaveData(iSaveData *apSaveData);
		virtual void LoadFromSaveData(iSaveData *apSaveData);
		virtual void SaveDataSetup(cSaveObjectHandler *apSaveObjectHandler, cGame *apGame);

	private:
		bool PlaySound(const tString &asName,bool abLoop,eSoundEntityType aType);

		float GetListenerSqrLength();

		cSoundEntityManager *mpSoundEntityManager;
		cSoundHandler *mpSoundHandler;
		cSoundEntityData *mpData;
		cWorld3D *mpWorld;

		iSoundChannel *mvSounds[3];
		//cSoundEntry *mvSoundEntries[3];
		int mvSoundId[3];

		bool mbStopped;
		bool mbRemoveWhenOver;

		bool mbOutOfRange;

		float mfIntervalCount;

		cSoundEntityChannelCallback *mpSoundCallback;

		bool mbStarted;

		bool mbFadingOut;

		bool mbLog;

		float mfVolume;

		bool mbPrioRemove;

		bool mbSkipStartEnd;

		float mfSleepCount;

		static tSoundEntityGlobalCallbackList mlstGobalCallbacks;
	};

};
#endif // HPL_SOUND_ENTITY_H
