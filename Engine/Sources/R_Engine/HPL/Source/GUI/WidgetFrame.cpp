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
#include "gui/WidgetFrame.h"

#include "system/LowLevelSystem.h"

#include "math/Math.h"

#include "gui/Gui.h"
#include "gui/GuiSkin.h"
#include "gui/GuiSet.h"
#include "gui/GuiGfxElement.h"

namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cWidgetFrame::cWidgetFrame(cGuiSet *apSet, cGuiSkin *apSkin) : iWidget(eWidgetType_Frame,apSet, apSkin)
	{
		mbClipsGraphics = true;

		mbDrawFrame = false;

		mbDrawBackground = false;
		mfBackgroundZ = -0.5;
		mBackGroundColor = cColor(1,1);
	}

	//-----------------------------------------------------------------------

	cWidgetFrame::~cWidgetFrame()
	{
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------


	//-----------------------------------------------------------------------


	//////////////////////////////////////////////////////////////////////////
	// PROTECTED METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	void cWidgetFrame::OnLoadGraphics()
	{
		mpGfxBackground = mpSkin->GetGfx(eGuiSkinGfx_FrameBackground);

		mvGfxBorders[0] = mpSkin->GetGfx(eGuiSkinGfx_FrameBorderRight);
		mvGfxBorders[1] = mpSkin->GetGfx(eGuiSkinGfx_FrameBorderLeft);
		mvGfxBorders[2] = mpSkin->GetGfx(eGuiSkinGfx_FrameBorderUp);
		mvGfxBorders[3] = mpSkin->GetGfx(eGuiSkinGfx_FrameBorderDown);

		mvGfxCorners[0] = mpSkin->GetGfx(eGuiSkinGfx_FrameCornerLU);
		mvGfxCorners[1] = mpSkin->GetGfx(eGuiSkinGfx_FrameCornerRU);
		mvGfxCorners[2] = mpSkin->GetGfx(eGuiSkinGfx_FrameCornerRD);
		mvGfxCorners[3] = mpSkin->GetGfx(eGuiSkinGfx_FrameCornerLD);
	}

	//-----------------------------------------------------------------------

	void cWidgetFrame::OnDraw(float afTimeStep, cGuiClipRegion *apClipRegion)
	{
		////////////////////////////////
		// Borders
		if(mbDrawFrame)
		{
			//Background must be drawn first!
			DrawBordersAndCorners(	NULL, mvGfxBorders, mvGfxCorners,
									GetGlobalPosition() -
										cVector3f(	mvGfxCorners[0]->GetActiveSize().x,
													mvGfxCorners[0]->GetActiveSize().y,0),
									mvSize +	mvGfxCorners[0]->GetActiveSize() +
												mvGfxCorners[2]->GetActiveSize());
		}
	}

	//-----------------------------------------------------------------------

	void cWidgetFrame::OnDrawAfterClip(float afTimeStep, cGuiClipRegion *apClipRegion)
	{
		////////////////////////////////
		// Background
		if(mbDrawBackground)
		{
			mpSet->DrawGfx(	mpGfxBackground,GetGlobalPosition() +cVector3f(0,0,mfBackgroundZ),
				mvSize,mBackGroundColor);
		}
	}

	//-----------------------------------------------------------------------

	bool cWidgetFrame::OnMouseMove(cGuiMessageData &aData)
	{
		return true;
	}

	//-----------------------------------------------------------------------

	bool cWidgetFrame::OnMouseDown(cGuiMessageData &aData)
	{
		return true;
	}

	//-----------------------------------------------------------------------

	bool cWidgetFrame::OnMouseUp(cGuiMessageData &aData)
	{
		return true;
	}

	//-----------------------------------------------------------------------

	bool cWidgetFrame::OnMouseEnter(cGuiMessageData &aData)
	{
		return false;
	}

	//-----------------------------------------------------------------------

	bool cWidgetFrame::OnMouseLeave(cGuiMessageData &aData)
	{
		return false;
	}

	//-----------------------------------------------------------------------


}
