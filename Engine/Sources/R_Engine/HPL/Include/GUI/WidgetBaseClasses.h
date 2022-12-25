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
#ifndef HPL_WIDGET_BASE_CLASSES_H
#define HPL_WIDGET_BASE_CLASSES_H

#include "gui/GuiTypes.h"

namespace hpl {

	//--------------------------------------

	class iWidgetItemContainer
	{
	public:
		void AddItem(const tWString &asItem);
		void RemoveItem(int alX);
		void RemoveItem(const tWString &asItem);

		const tWString& GetItem(int alX) const;
		void SetItem(int alX, const tWString& asText);
		int GetItemNum() const;
		bool HasItem(const tWString &asItem);

	protected:
		virtual void UpdateProperties()=0;

		tWStringVec mvItems;
	};

	//--------------------------------------

};
#endif // HPL_WIDGET_BASE_CLASSES_H
