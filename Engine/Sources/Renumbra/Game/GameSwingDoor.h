/*
 * Copyright (C) 2006-2010 - Frictional Games
 *
 * This file is part of Penumbra Overture.
 *
 * Penumbra Overture is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Penumbra Overture is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Penumbra Overture.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GAME_GAME_SWING_DOOR_H
#define GAME_GAME_SWING_DOOR_H

#include "StdAfx.h"
#include "GameEntity.h"

using namespace hpl;

//----------------------------------------------

class cGameSwingDoor_SaveData : public iGameEntity_SaveData
{
	kSerializableClassInit(cGameSwingDoor_SaveData);
public:
	bool mbLocked;

	tString msBreakSound;
	tString msBreakEntity;
	tString msBreakPS;

	iGameEntity* CreateEntity();
};

//----------------------------------------------

class cGameSwingJointDefault
{
public:
	float mfMin;
	float mfMax;
};
//----------------------------------------------


class cGameSwingDoor :	public iGameEntity
{
#ifdef __GNUC__
	typedef iGameEntity __super;
#endif
friend class cEntityLoader_GameSwingDoor;
public:
	cGameSwingDoor(cInit *apInit,const tString& asName);
	~cGameSwingDoor(void);

	void OnPlayerInteract();
	void OnPlayerPick();

	void Update(float afTimeStep);

	void OnDamage(float afDamage);
	void OnDeath(float afDamage);

	void BreakAction();

	void SetupBreakObject();

	void SetupPhysics(cWorld3D *apWorld);

	void SetLocked(bool abX);

	//SaveObject implementation
	iGameEntity_SaveData* CreateSaveData();
	void SaveToSaveData(iGameEntity_SaveData *apSaveData);
	void LoadFromSaveData(iGameEntity_SaveData *apSaveData);

private:
	std::vector<iPhysicsController*> mvStopControllers;
	std::vector<cGameSwingJointDefault> mvJointDefaults;

	bool mbLocked;

	tString msBreakSound;
	tString msBreakEntity;
	tString msBreakPS;
};

//--------------------------------------

class cEntityLoader_GameSwingDoor : public cEntityLoader_Object
{
public:
	cEntityLoader_GameSwingDoor(const tString &asName, cInit *apInit);
	~cEntityLoader_GameSwingDoor();

private:
	void BeforeLoad(TiXmlElement *apRootElem, const cMatrixf &a_mtxTransform,cWorld3D *apWorld);
	void AfterLoad(TiXmlElement *apRootElem, const cMatrixf &a_mtxTransform,cWorld3D *apWorld);

	cInit *mpInit;
};


#endif // GAME_GAME_SWING_DOOR_H
