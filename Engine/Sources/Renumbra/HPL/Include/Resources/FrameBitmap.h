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
#ifndef HPL_FRAMEBITMAP_H
#define HPL_FRAMEBITMAP_H

#include "resources/FrameBase.h"
#include "system/BinTree.h"
#include "math/MathTypes.h"

namespace hpl {

	class cFrameTexture;
	class cResourceImage;
	class iBitmap2D;

	//The frames bitmap + rect class
	class cFBitmapRect
	{
	public:
		cFBitmapRect(){mlHandle=-1;}
		cFBitmapRect(int x,int y,int w,int h, int alHandle){
			mRect = cRect2l(x,y,w,h);
			mlHandle = alHandle;
		}

		cRect2l mRect;
		int mlHandle;
	};

	typedef BinTree<cFBitmapRect> tRectTree;
	typedef BinTreeNode<cFBitmapRect> tRectTreeNode;
	typedef std::list<tRectTreeNode*> tRectTreeNodeList;
	typedef tRectTreeNodeList::iterator tRectTreeNodeListIt;

	class cFrameBitmap : public iFrameBase
	{
	public:
		cFrameBitmap(iBitmap2D *apBitmap, cFrameTexture *apFrmTex, int alHandle);
		~cFrameBitmap();

		cResourceImage * AddBitmap(iBitmap2D *apSrc);
		bool MinimumFit(cRect2l aSrc,cRect2l aDest);
		bool IsFull();
		bool IsUpdated();

		bool IsLocked()const { return mbIsLocked;}
		void SetLocked(bool abX){ mbIsLocked = abX; }

		bool FlushToTexture();

		cFrameTexture* GetFrameTexture(){ return mpFrameTexture;}

		int GetHandle()const{ return mlHandle; }
	private:
		iBitmap2D* mpBitmap;
		cFrameTexture* mpFrameTexture;
		tRectTree mRects;
		int mlMinHole;
		int mlHandle;
		bool mbIsFull;
		bool mbIsUpdated;
		bool mbIsLocked;
	};

};
#endif // HPL_FRAMEBITMAP_H
