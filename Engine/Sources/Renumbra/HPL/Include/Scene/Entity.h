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
#ifndef HPL_ENTITY_H
#define HPL_ENTITY_H

#include "math/MathTypes.h"
#include "system/SystemTypes.h"
#include "game/SaveGame.h"

namespace hpl {

	class iNode;

	//------------------------------------

	kSaveData_BaseClass(iEntity)
	{
		kSaveData_ClassInit(iEntity)
	public:
		int mlParentNodeId;
		tString msName;
		bool mbIsVisible;
		bool mbIsActive;
	};

	//------------------------------------

	class iEntity : public iSaveObject
	{
	#ifdef __GNUC__
		typedef iSaveObject __super;
	#endif
	public:
		iEntity(tString asName) : msName(asName), mbIsVisible(true),
			mbIsActive(true), mpParentNode(NULL) {}

		virtual ~iEntity();

		virtual tString GetEntityType()=0;

		virtual void UpdateLogic(float afTimeStep){}

		tString& GetName(){return msName;}
		void SetName(const tString& asName){msName = asName;}

		iNode* GetParent(){ return mpParentNode;}
		void SetParent(iNode* apNode){ mpParentNode = apNode;}
		bool HasParent(){ return mpParentNode!=NULL;}

		bool IsActive(){ return mbIsActive; }
		void SetActive(bool abActive){ mbIsActive = abActive; }
		virtual bool IsVisible(){ return mbIsVisible; }
		virtual void SetVisible(bool abVisible){ mbIsVisible = abVisible; }

		//SaveObject implementation
		virtual iSaveData* CreateSaveData();
		virtual void SaveToSaveData(iSaveData *apSaveData);
		virtual void LoadFromSaveData(iSaveData *apSaveData);
		virtual void SaveDataSetup(cSaveObjectHandler *apSaveObjectHandler, cGame *apGame);

	protected:
		iNode* mpParentNode;

		tString msName;
		bool mbIsVisible;
		bool mbIsActive;
	};

	typedef std::list<iEntity*> tEntityList;
	typedef tEntityList::iterator tEntityListIt;

	typedef cSTLIterator<iEntity*,tEntityList,tEntityListIt> cEntityIterator;

};
#endif // HPL_ENTITY2D_H
