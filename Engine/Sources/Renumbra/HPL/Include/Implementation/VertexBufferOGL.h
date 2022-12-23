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
#ifndef HPL_VERTEXBUFFER_OGL_H
#define HPL_VERTEXBUFFER_OGL_H

#include "graphics/VertexBuffer.h"

namespace hpl {

	class cVertexBufferOGL : public iVertexBuffer
	{
	public:
		cVertexBufferOGL(iLowLevelGraphics* apLowLevelGraphics,tVertexFlag aFlags,
			eVertexBufferDrawType aDrawType,eVertexBufferUsageType aUsageType,
			int alReserveVtxSize,int alReserveIdxSize);
		~cVertexBufferOGL();

		void AddVertex(tVertexFlag aType,const cVector3f& avVtx);
		void AddColor(tVertexFlag aType,const cColor& aColor);
		void AddIndex(unsigned int alIndex);

		bool Compile(tVertexCompileFlag aFlags);
		void UpdateData(tVertexFlag aTypes, bool abIndices);

		void CreateShadowDouble(bool abUpdateData);

		void Transform(const cMatrixf &mtxTransform);

		void Draw(eVertexBufferDrawType aDrawType);
		void DrawIndices(unsigned int *apIndices, int alCount,
			eVertexBufferDrawType aDrawType = eVertexBufferDrawType_LastEnum);


		void Bind();
		void UnBind();

		iVertexBuffer* CreateCopy(eVertexBufferUsageType aUsageType);

		cBoundingVolume CreateBoundingVolume();

		float* GetArray(tVertexFlag aType);
		unsigned int* GetIndices();

		void ResizeArray(tVertexFlag aType, int alSize);
		void ResizeIndices(int alSize);

		//For debugging purposes
		int GetVertexNum();
		int GetIndexNum();

		cVector3f GetVector3(tVertexFlag aType, unsigned alIdx);
		cVector3f GetVector4(tVertexFlag aType, unsigned alIdx);
		cColor GetColor(tVertexFlag aType, unsigned alIdx);
		unsigned int GetIndex(tVertexFlag aType, unsigned alIdx);


	private:
		void SetVertexStates(tVertexFlag aFlags);

		tFloatVec mvVertexArray[klNumOfVertexFlags];
		tUIntVec mvIndexArray;

		bool mbTangents;

		bool mbHasShadowDouble;
	};

};
#endif // HPL_RENDERER3D_OGL_H
