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
#ifndef HPL_WIDGET_COMBO_BOX_H
#define HPL_WIDGET_COMBO_BOX_H

#include "gui/Widget.h"
#include "gui/WidgetBaseClasses.h"

namespace hpl {

	class cGuiSkinFont;

	class cWidgetTextBox;
	class cWidgetButton;
	class cWidgetSlider;

	class cWidgetComboBox : public iWidget, public iWidgetItemContainer
	{
	public:
		cWidgetComboBox(cGuiSet *apSet, cGuiSkin *apSkin);
		virtual ~cWidgetComboBox();

		void SetSelectedItem(int alX,bool abMoveList=false);
		int GetSelectedItem(){ return mlSelectedItem;}

		void SetCanEdit(bool abX);
		bool GetCanEdit();

		void SetMaxShownItems(int alX);
		int GetMaxShownItems(){ return mlMaxItems;}

	protected:
		/////////////////////////
		// Own functions
		void UpdateProperties();

		void OpenMenu();
		void CloseMenu();

		bool ButtonPress(iWidget* apWidget,cGuiMessageData& aData);
		kGuiCalllbackDeclarationEnd(ButtonPress);

		bool DrawText(iWidget* apWidget,cGuiMessageData& aData);
		kGuiCalllbackDeclarationEnd(DrawText);

		bool SliderMove(iWidget* apWidget,cGuiMessageData& aData);
		kGuiCalllbackDeclarationEnd(SliderMove);

		bool SliderLostFocus(iWidget* apWidget,cGuiMessageData& aData);
		kGuiCalllbackDeclarationEnd(SliderLostFocus);

		/////////////////////////
		// Implemented functions
		void OnLoadGraphics();
		void OnChangeSize();
		void OnChangeText();
		void OnInit();

		void OnDraw(float afTimeStep, cGuiClipRegion *apClipRegion);

		bool OnMouseMove(cGuiMessageData &aData);
		bool OnMouseDown(cGuiMessageData &aData);
		bool OnMouseUp(cGuiMessageData &aData);
		bool OnMouseEnter(cGuiMessageData &aData);
		bool OnMouseLeave(cGuiMessageData &aData);

		bool OnLostFocus(cGuiMessageData &aData);


		/////////////////////////
		// Data
		cWidgetTextBox *mpText;
		cWidgetButton *mpButton;
		cWidgetSlider *mpSlider;

		bool mbMenuOpen;
		float mfMenuHeight;

		float mfButtonWidth;
		float mfSliderWidth;

		int mlMouseOverSelection;
		int mlSelectedItem;
		int mlFirstItem;
		int mlMaxItems;
		int mlItemsShown;

		cGuiGfxElement *mpGfxBackground;

		cGuiGfxElement *mpGfxSelection;

		cGuiGfxElement *mvGfxBorders[4];
		cGuiGfxElement *mvGfxCorners[4];
	};

};
#endif // HPL_WIDGET_COMBO_BOX_H
