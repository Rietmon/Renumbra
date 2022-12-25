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
#ifndef HPL_GUI_MATERIAL_BASIC_TYPES_H
#define HPL_GUI_MATERIAL_BASIC_TYPES_H

#include "gui/GuiMaterial.h"

namespace hpl {

	//-----------------------------------------

	class cGuiMaterial_Diffuse : public iGuiMaterial
	{
	public:
		cGuiMaterial_Diffuse(iLowLevelGraphics *apLowLevelGraphics):iGuiMaterial("Diffuse",apLowLevelGraphics){}
		~cGuiMaterial_Diffuse(){}

		void BeforeRender();
		void AfterRender();
	};

	//-----------------------------------------

	class cGuiMaterial_Alpha : public iGuiMaterial
	{
	public:
		cGuiMaterial_Alpha(iLowLevelGraphics *apLowLevelGraphics):iGuiMaterial("Alpha",apLowLevelGraphics){}
		~cGuiMaterial_Alpha(){}

		void BeforeRender();
		void AfterRender();
	};

	//-----------------------------------------

	class cGuiMaterial_FontNormal : public iGuiMaterial
	{
	public:
		cGuiMaterial_FontNormal(iLowLevelGraphics *apLowLevelGraphics):iGuiMaterial("FontNormal",apLowLevelGraphics){}
		~cGuiMaterial_FontNormal(){}

		void BeforeRender();
		void AfterRender();
	};

	//-----------------------------------------

	class cGuiMaterial_Additive : public iGuiMaterial
	{
	public:
		cGuiMaterial_Additive(iLowLevelGraphics *apLowLevelGraphics):iGuiMaterial("Additive",apLowLevelGraphics){}
		~cGuiMaterial_Additive(){}

		void BeforeRender();
		void AfterRender();
	};

	//-----------------------------------------

	class cGuiMaterial_Modulative : public iGuiMaterial
	{
	public:
		cGuiMaterial_Modulative(iLowLevelGraphics *apLowLevelGraphics):iGuiMaterial("Modulative",apLowLevelGraphics){}
		~cGuiMaterial_Modulative(){}

		void BeforeRender();
		void AfterRender();
	};

	//-----------------------------------------

};
#endif // HPL_GUI_MATERIAL_BASIC_TYPES_H
