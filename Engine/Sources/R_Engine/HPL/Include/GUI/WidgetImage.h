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
#ifndef HPL_WIDGET_IMAGE_H
#define HPL_WIDGET_IMAGE_H

#include "gui/Widget.h"

namespace hpl {

	class cGuiSkinFont;

	class cWidgetImage : public iWidget
	{
	public:
		cWidgetImage(cGuiSet *apSet, cGuiSkin *apSkin);
		virtual ~cWidgetImage();

		void SetImage(cGuiGfxElement *apGfx);
		cGuiGfxElement* GetImage(){ return mpGfxImage;}

	protected:
		/////////////////////////
		// Implemented functions
		void OnLoadGraphics();
		void OnChangeSize();

		void OnDraw(float afTimeStep, cGuiClipRegion *apClipRegion);

		bool OnMouseMove(cGuiMessageData &aData);
		bool OnMouseDown(cGuiMessageData &aData);
		bool OnMouseUp(cGuiMessageData &aData);
		bool OnMouseEnter(cGuiMessageData &aData);
		bool OnMouseLeave(cGuiMessageData &aData);

		/////////////////////////
		// Data
		cGuiGfxElement *mpGfxImage;
		cColor mColor;
	};

};
#endif // HPL_WIDGET_IMAGE_H
