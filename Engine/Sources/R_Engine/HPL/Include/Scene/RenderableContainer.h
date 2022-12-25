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
#ifndef HPL_RENDERABLE_CONTAINER_H
#define HPL_RENDERABLE_CONTAINER_H

#include "math/MathTypes.h"
#include "graphics/GraphicsTypes.h"
#include "system/SystemTypes.h"

namespace hpl {

	class iRenderable;
	class cFrustum;
	class cRenderList;

	class iRenderableContainer
	{
	public:
		/**
		 * Add a new object to the container.
		 * \param *apRenderable the object
		 * \param abStatic true if the object will not move, else false.
		 * \return true if success, else false
		 */
		virtual bool Add(iRenderable *apRenderable, bool abStatic)=0;
		/**
		 * Removes the object, only non static are guaranteed to be found.
		 * \param *apRenderable the object
		 * \return true if success, else false
		 */
		virtual bool Remove(iRenderable *apRenderable)=0;

		/**
		 * Populate the renderlist with all objects visible in a fostrum.
		 * \param apFostrum
		 * \param *apRenderList
		 */
		virtual void GetVisible(cFrustum* apFostrum,cRenderList *apRenderList)=0;

		/**
		* Sets up things like octrees so that the container is ready to use.
		*/
		virtual void Compile()=0;
	};
};
#endif // RENDERABLE_CONTAINER
