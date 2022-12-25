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
#ifndef HPL_MOUSE_H
#define HPL_MOUSE_H

#include "input/InputTypes.h"
#include "input/InputDevice.h"
#include "math/MathTypes.h"

namespace hpl {

	class iMouse : public iInputDevice
	{
	public:
		iMouse(tString asName);
		virtual ~iMouse(){}

		/**
		 * Check if a mouse button is down
		 * \param eMButton the button to check
		 * \return
		 */
		virtual bool ButtonIsDown(eMButton)=0;
		/**
		 * Get the absolute pos of the mouse.
		 * \return
		 */
		virtual cVector2f GetAbsPosition()=0;
		/**
		 * Get the relative movement.
		 * \return
		 */
		virtual cVector2f GetRelPosition()=0;

		/**
		 * Reset smoothing and relative movement.
		 */
		virtual void Reset()=0;
		/**
		 * Set parameters for mouse smoothing
		 * \param afMinPercent Influence of the oldest position.
		 * \param afMaxPercent Influence of the latest position.
		 * \param alBufferSize number of saved positions, 1 = no smoothing
		 */
		virtual void SetSmoothProperties(float afMinPercent,
										float afMaxPercent,unsigned int alBufferSize)=0;
	};

};

#endif // HPL_MOUSE_H
