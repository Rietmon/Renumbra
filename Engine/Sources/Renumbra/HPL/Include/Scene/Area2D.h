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
#ifndef HPL_AREA2D_H
#define HPL_AREA2D_H

#include "scene/Entity2D.h"
class TiXmlElement;

namespace hpl {

	class cBody2D;
	class cCollider2D;

	class cArea2D : public iEntity2D
	{
	public:
		cArea2D(const tString& asName,const tString& asTypeName,cCollider2D* apCollider);
		~cArea2D();

		tString GetEntityType(){ return "Area";}
		const tString& GetType(){ return msType;}
		const cVector3f& GetCustom(){ return mvCustom;}
		const cVector2f& GetSize(){ return mvSize;}

		bool LoadData(TiXmlElement* apRootElem);

		bool CheckWorldCollision(tFlag alFlags);
		bool CheckBodyCollision(cBody2D *apBody);

		const cRect2f& GetBoundingBox();
		bool UpdateBoundingBox();

	private:
		cCollider2D* mpCollider;

		tString msType;

		cVector2f mvSize;
		cVector3f mvCustom;
	};

};
#endif // HPL_AREA2D_H
