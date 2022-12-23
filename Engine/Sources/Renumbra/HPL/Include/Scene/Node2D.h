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
#ifndef HPL_NODE2D_H
#define HPL_NODE2D_H

#include <list>
#include "math/MathTypes.h"
#include "scene/Node.h"

namespace hpl {

	class cNode2D : public iNode
	{
	public:
		cNode2D();
		virtual ~cNode2D();

		iNode* CreateChild();
		cNode2D* CreateChild2D();

		cVector3f& GetPosition() { return mvPosition; }
		cVector3f& GetRotation(){ return mvRotation; }
		cVector3f& GetScale(){ return mvScale; }

		void SetPosition(cVector3f avPos);
		void SetRotation(cVector3f avRot);
		void SetScale(cVector3f avScale);

	private:
		cVector3f mvPosition;
		cVector3f mvRotation;
		cVector3f mvScale;

	};

};
#endif // HPL_NODE2D_H
