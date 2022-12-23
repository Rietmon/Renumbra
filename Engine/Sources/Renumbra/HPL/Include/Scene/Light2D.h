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
#ifndef HPL_LIGHT2D_H
#define HPL_LIGHT2D_H

#include <list>
#include "scene/Entity2D.h"
#include "scene/Light.h"
#include "graphics/GraphicsTypes.h"

namespace hpl {

	class iLowLevelGraphics;

	class iLight2D : public iEntity2D, public iLight
	{
	public:
		iLight2D(tString asName);
		virtual ~iLight2D(){}

		tString GetEntityType(){ return "iLight2D";}

		void UpdateLogic(float afTimeStep);

		void SetFarAttenuation(float afX);
		void SetNearAttenuation(float afX);

		cVector3f GetLightPosition();

		virtual int Render(iLowLevelGraphics* apLowLevel, int alFirstIndex)=0;

	protected:
	};

	typedef std::list<iLight2D*> tLightList;
	typedef tLightList::iterator tLightListIt;
};
#endif // HPL_LIGHT2D_H
