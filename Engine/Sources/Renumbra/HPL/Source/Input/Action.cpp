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
#include "input/Action.h"
#include "system/LowLevelSystem.h"

namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	iAction::iAction(tString asName)
	{
		msName = asName;

		mbBecameTriggerd= false;
		mbIsTriggerd = false;

		mfTimeCount = -1.0;

		mbTriggerDown = false;
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	bool iAction::WasTriggerd()
	{
		if(mbBecameTriggerd && !IsTriggerd()){
			mbBecameTriggerd=false;
			return true;
		}

		return false;
	}

	//-----------------------------------------------------------------------

	bool iAction::BecameTriggerd()
	{
		if(!mbIsTriggerd && IsTriggerd()){
			mbIsTriggerd=true;
			return true;
		}

		return false;
	}

	//-----------------------------------------------------------------------

	bool iAction::DoubleTriggerd(float afLimit)
	{
		if(!mbTriggerDown && IsTriggerd())
		{
			mbTriggerDown=true;

			if(mfTimeCount <0 || mfTimeCount > afLimit)
			{
				mfTimeCount =0;
				return false;
			}
			else
			{
				mfTimeCount =0;
				mbIsTriggerd=true;
				return true;
			}
		}

		return false;
	}

	//-----------------------------------------------------------------------

	void iAction::Update(float afTimeStep)
	{
		UpdateLogic(afTimeStep);

		if(!IsTriggerd()){
			mbIsTriggerd=false;
			mbTriggerDown = false;

			if(mfTimeCount >= 0) mfTimeCount += afTimeStep;
		}
		else {
			mbBecameTriggerd=true;
		}
	}

	//-----------------------------------------------------------------------

	void iAction::UpdateLogic(float afTimeStep)
	{
	}

	//-----------------------------------------------------------------------

	tString iAction::GetName()
	{
		return msName;
	}

	//-----------------------------------------------------------------------

}
