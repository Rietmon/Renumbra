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
#ifndef HPL_GUI_H
#define HPL_GUI_H

#include <map>

#include "game/Updateable.h"

#include "gui/GuiTypes.h"
#include "system/SystemTypes.h"

namespace hpl {

	class cResources;
	class cGraphics;
	class cSound;
	class cScene;

	class cGuiSet;
	class cGuiSkin;
	class cGuiGfxElement;

	class iGuiMaterial;

	//------------------------------------------------

	typedef std::map<tString, cGuiSet*> tGuiSetMap;
	typedef tGuiSetMap::iterator tGuiSetMapIt;

	//-------------------------------------

	typedef std::map<tString, cGuiSkin*> tGuiSkinMap;
	typedef tGuiSkinMap::iterator tGuiSkinMapIt;

	//-------------------------------------

	typedef std::map<tString, eGuiSkinGfx> tGuiSkinGfxMap;
	typedef tGuiSkinGfxMap::iterator tGuiSkinGfxMapIt;

	typedef std::map<tString, eGuiSkinFont> tGuiSkinFontMap;
	typedef tGuiSkinFontMap::iterator tGuiSkinFontMapIt;

	typedef std::map<tString, eGuiSkinAttribute> tGuiSkinAttributeMap;
	typedef tGuiSkinAttributeMap::iterator tGuiSkinAttributeMapIt;


	//------------------------------------------------

	class cGui : public iUpdateable
	{
	public:
		cGui();
		~cGui();

		///////////////////////////////
		// General

		void Init(	cResources *apResources, cGraphics* apGraphics,
					cSound *apSound, cScene *apScene);

		void Update(float afTimeStep);

		void OnPostSceneDraw();
		void OnPostGUIDraw();

		iGuiMaterial* GetMaterial(eGuiMaterial aType);

		///////////////////////////////
		// Skins
		cGuiSkin* CreateSkin(const tString& asFile);

		eGuiSkinGfx GetSkinGfxFromString(const tString& asType);
		eGuiSkinFont GetSkinFontFromString(const tString& asType);
		eGuiSkinAttribute GetSkinAttributeFromString(const tString& asType);

		///////////////////////////////
		// Sets
		cGuiSet* CreateSet(const tString& asName, cGuiSkin *apSkin);
		cGuiSet* GetSetFromName(const tString& asName);
		void SetFocus(cGuiSet* apSet);
		void SetFocusByName(const tString& asSetName);
		cGuiSet* GetFocusedSet(){return mpSetInFocus;}
		void DestroySet(cGuiSet *apSet);

		///////////////////////////////
		// Graphics creation
		cGuiGfxElement* CreateGfxFilledRect(const cColor& aColor, eGuiMaterial aMaterial, bool abAddToList=true);
		cGuiGfxElement* CreateGfxImage(	const tString &asFile,eGuiMaterial aMaterial,
										const cColor& aColor=cColor(1,1), bool abAddToList=true);
		cGuiGfxElement* CreateGfxTexture(const tString &asFile,eGuiMaterial aMaterial,
										const cColor& aColor=cColor(1,1), bool abMipMaps=false,
										bool abAddToList=true);
		//Loads several images asFile+00, etc. Used for animations.
		//Must have extension!
		cGuiGfxElement* CreateGfxImageBuffer(	const tString &asFile,eGuiMaterial aMaterial,
												bool abCreateAnimation=true,
												const cColor& aColor=cColor(1,1), bool abAddToList=true);

		void DestroyGfx(cGuiGfxElement* apGfx);

		///////////////////////////////
		// Input sending
		bool SendMousePos(const cVector2f &avPos, const cVector2f &avRel);
		bool SendMouseClickDown(eGuiMouseButton aButton);
		bool SendMouseClickUp(eGuiMouseButton aButton);
		bool SendMouseDoubleClick(eGuiMouseButton aButton);

		bool SendKeyPress(const cKeyPress& keyPress);

		//bool SentArrowKey(eGuiArrowKey aDir);


		///////////////////////////////
		// Properties
		cResources* GetResources(){ return mpResources;}

	private:
		void GenerateSkinTypeStrings();

		cResources *mpResources;
		cGraphics *mpGraphics;
		cSound *mpSound;
		cScene *mpScene;

		cGuiSet *mpSetInFocus;

		tGuiSetMap m_mapSets;
		tGuiSkinMap m_mapSkins;

		iGuiMaterial *mvMaterials[eGuiMaterial_LastEnum];

		tGuiGfxElementList mlstGfxElements;

		tGuiSkinGfxMap m_mapSkinGfxStrings;
		tGuiSkinFontMap m_mapSkinFontStrings;
		tGuiSkinAttributeMap m_mapSkinAttributeStrings;

		unsigned long mlLastRenderTime;
	};

};
#endif // HPL_GUI_H
