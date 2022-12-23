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
#ifndef HPL_NODE_H
#define HPL_NODE_H

#include <list>
#include "scene/Entity.h"
#include "math/MathTypes.h"
#include "system/Container.h"
#include "game/SaveGame.h"

namespace hpl {

	class iNode;

	typedef std::list<iNode*> tNodeList;
	typedef tNodeList::iterator tNodeListIt;

	typedef cSTLIterator<iNode*,tNodeList,tNodeListIt> cNodeIterator;

	//------------------------------------

	kSaveData_BaseClass(iNode)
	{
		kSaveData_ClassInit(iNode)
	public:
		cContainerList<int> mlstEntities;
		cContainerList<int> mlstNodes;
	};

	//------------------------------------

	class iNode : public iSaveObject
	{
	#ifdef __GNUC__
		typedef iSaveObject __super;
	#endif
	public:
		iNode() : mbActive(true){}
		virtual ~iNode();

		int SetVisible(bool abX, bool abCascade);
		bool AddEntity(iEntity* apEntity);
		bool RemoveEntity(iEntity* apEntity);
		void ClearEntities();

		void SetActive(bool abX){mbActive = abX;}
		bool IsActive(){return mbActive;}

		virtual iNode* CreateChild()=0;

		cNodeIterator GetChildIterator();
		cEntityIterator GetEntityIterator();

		//SaveObject implementation
		virtual iSaveData* CreateSaveData(){return NULL;}
		virtual void SaveToSaveData(iSaveData *apSaveData);
		virtual void LoadFromSaveData(iSaveData *apSaveData);
		virtual void SaveDataSetup(cSaveObjectHandler *apSaveObjectHandler, cGame *apGame);

	protected:
		tEntityList mlstEntity;
		tNodeList mlstNode;

		bool mbActive;
	};

};
#endif // HPL_NODE_H
