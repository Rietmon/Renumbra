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
#ifndef HPL_FRAMEBASE_H
#define HPL_FRAMEBASE_H

#include "math/MathTypes.h"

namespace hpl {

	class iFrameBase
	{
	public:
		iFrameBase(){
			mlPicCount = 0;
		}

		void SetPicCount(int alPicCount){mlPicCount=alPicCount;}
		void DecPicCount(){if(mlPicCount>0)mlPicCount--;}
		int GetPicCount(){return mlPicCount;}
		bool IsEmpty() {return mlPicCount<=0;}

	protected:
		int mlPicCount;
	};

};
#endif // HPL_FRAMEBASE_H
