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
#include "impl/SDLBitmap2D.h"



namespace hpl {

	//////////////////////////////////////////////////////////////////////////
	// CONSTRUCTORS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	cSDLBitmap2D::cSDLBitmap2D(iPixelFormat *apPxlFmt) : iBitmap2D("SDL",apPxlFmt)
	{
		mpSurface = NULL;
		mlHeight = 0;
		mlWidth = 0;

		cSDLPixelFormat *pFmt = static_cast<cSDLPixelFormat*>(apPxlFmt);
		mpSDLPixelFmt32 = pFmt->GetSDLPixelFormat32();
	}

	cSDLBitmap2D::cSDLBitmap2D(SDL_Surface* apSurface,iPixelFormat *apPxlFmt,const tString& asType) :
	iBitmap2D("SDL",apPxlFmt)
	{
		mpSurface = apSurface;
		mlHeight = mpSurface->h;
		mlWidth = mpSurface->w;

		msType = asType;

		cSDLPixelFormat *pFmt = static_cast<cSDLPixelFormat*>(apPxlFmt);
		mpSDLPixelFmt32 = pFmt->GetSDLPixelFormat32();
	}
	cSDLBitmap2D::~cSDLBitmap2D()
	{
		SDL_FreeSurface(mpSurface);
	}

	//-----------------------------------------------------------------------

	//////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////

	//-----------------------------------------------------------------------

	bool cSDLBitmap2D::SaveToFile(const tString& asFile)
	{
		return false;
	}

	//-----------------------------------------------------------------------

	void cSDLBitmap2D::DrawToBitmap(iBitmap2D *apDest, const cVector2l &avDestPos)
	{
		cSDLBitmap2D* pBmp = static_cast<cSDLBitmap2D*>(apDest);

		SDL_Rect rect;
		rect.x = avDestPos.x;
		rect.y = avDestPos.y;

		int lDestSize = pBmp->GetSurface()->format->BytesPerPixel;
		int lSrcSize = mpSurface->format->BytesPerPixel;

		unsigned char* destBuffer = (unsigned char*)pBmp->GetSurface()->pixels;
		unsigned char* srcBuffer = (unsigned char*)mpSurface->pixels;

		SDL_BlitSurface(mpSurface, NULL, pBmp->GetSurface(),&rect);

		//do this little hack to set the alpha to a correct value.
		//stupid SDL always sets it to 255..
		if(lDestSize!=4 || lSrcSize!=4)return;

		for(unsigned int y=0;y<mlHeight;y++)
			for(unsigned int x=0;x<mlWidth;x++)
			{
				unsigned char* destPix = &destBuffer[((y + avDestPos.y)*pBmp->GetWidth() +
													(x + avDestPos.x)) * lDestSize];

				unsigned char* srcPix = &srcBuffer[(y*mlWidth + x) * lSrcSize];

				destPix[3] = srcPix[3];
			}
	}

	//-----------------------------------------------------------------------

	void cSDLBitmap2D::FillRect(const cRect2l &aRect, const cColor &aColor)
	{
		SDL_Rect rect;
		rect.x = aRect.x;
		rect.y = aRect.y;
		rect.w = aRect.w<=0?mlWidth:aRect.w;
		rect.h = aRect.h<=0?mlHeight:aRect.h;

		unsigned int col = SDL_MapRGBA(mpSDLPixelFmt32,(int)(aColor.r*255.0f),(int)(aColor.g*255.0f),
										(int)(aColor.b*255.0f),(int)(aColor.a*255.0f));

		SDL_FillRect(mpSurface, &rect,col);
	}

	//-----------------------------------------------------------------------

	bool cSDLBitmap2D::HasAlpha()
	{
		return true;
	}

	//-----------------------------------------------------------------------

	bool cSDLBitmap2D::Create(cVector2l avSize, unsigned int alBpp)
	{
		mpSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, avSize.x, avSize.y, 32,
			mpSDLPixelFmt32->Rmask, mpSDLPixelFmt32->Gmask,
			mpSDLPixelFmt32->Bmask, mpSDLPixelFmt32->Amask);

		if(mpSurface==NULL) return false;

		mlHeight = mpSurface->h;
		mlWidth = mpSurface->w;

		return true;
	}

	//-----------------------------------------------------------------------

	SDL_Surface* cSDLBitmap2D::GetSurface()
	{
		return mpSurface;
	}

	//-----------------------------------------------------------------------

	void* cSDLBitmap2D::GetRawData()
	{
		return mpSurface->pixels;
	}

	int cSDLBitmap2D::GetNumChannels()
	{
		return mpSurface->format->BytesPerPixel;
	}

	//-----------------------------------------------------------------------

}
