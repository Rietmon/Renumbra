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
#ifndef HPL_ENTITY2D_H
#define HPL_ENTITY2D_H

#include "math/MathTypes.h"
#include "system/SystemTypes.h"
#include "scene/Entity.h"

namespace hpl {

	class cGrid2DObject;

	class iEntity2D : public iEntity
	{
	public:
		iEntity2D(tString asName);
		virtual ~iEntity2D(){}

		virtual const cRect2f& GetBoundingBox()=0;
		virtual bool UpdateBoundingBox()=0;

		cVector3f& GetLocalPosition(){ return mvPosition; }
		cVector3f& GetLocalRotation(){ return mvRotation; }
		cVector3f& GetLocalScale(){ return mvScale; }

		cVector3f GetWorldPosition();
		cVector3f GetWorldRotation();
		cVector3f GetWorldScale();

		void SetPosition(const cVector3f& avPos);
		void SetRotation(const cVector3f& avRot);
		void SetScale(const cVector3f& avScale);

		cGrid2DObject* GetGrid2DObject(){ return mpGridObject;}
		void SetGrid2DObject(cGrid2DObject* apGrid){ mpGridObject = apGrid;}
		bool HasGrid2DObject(){ return mpGridObject!=NULL;}


	protected:
		cGrid2DObject* mpGridObject;

		cVector3f mvPosition;
		cVector3f mvRotation;
		cVector3f mvScale;

		cVector3f mvLastPosition;
		cVector3f mvLastRotation;
		cVector3f mvLastScale;

		cRect2f mBoundingBox;
	};

	typedef std::list<iEntity2D*> tEntity2DList;
	typedef tEntity2DList::iterator tEntity2DListIt;

};
#endif // HPL_ENTITY2D_H
