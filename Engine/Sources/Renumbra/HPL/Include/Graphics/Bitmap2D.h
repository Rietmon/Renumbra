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
#ifndef HPL_BITMAP2D_H
#define HPL_BITMAP2D_H

#include "graphics/LowLevelPicture.h"
#include "math/MathTypes.h"
#include "graphics/GraphicsTypes.h"


namespace hpl {

	class iPixelFormat;

	class iBitmap2D : public iLowLevelPicture
	{
	public:
		iBitmap2D(tString asType,iPixelFormat *apPxlFmt) : iLowLevelPicture(asType){}
		virtual ~iBitmap2D() {}

		/**
		 * Save the bitmap to file
		 * \param asFile
		 * \return
		 */
		virtual bool SaveToFile(const tString& asFile)=0;

		/**
		 * Draw the bitmap onto another
		 * \param *apBmp Destination
		 * \param &avPos Position on new map
		 */
		virtual void DrawToBitmap(iBitmap2D *apBmp, const cVector2l &avPos)=0;
		/**
		 * Creates a new size for the bitmap. (all previous content is erased
		 * \param avSize
		 * \param alBpp
		 * \return
		 */
		virtual bool Create(cVector2l avSize, unsigned int alBpp)=0;

		/**
		 * Draws a solid rect onto the bitmap. IF h and w is than w and how of the bitmap is used.
		 * \param &aRect
		 * \param &aColor
		 */
		virtual void FillRect(const cRect2l &aRect, const cColor &aColor)=0;

		/**
		 * Get a pointer to the raw pixel data.
		 */
		virtual void* GetRawData()=0;

		/**
		 * Get the number of color channels in the image.
		 * \return
		 */
		virtual int GetNumChannels()=0;
	};

	typedef std::vector<iBitmap2D*> tBitmap2DVec;
	typedef std::vector<iBitmap2D*>::iterator tBitmap2DVecIt;

};
#endif // HPL_BITMAP2D_H
