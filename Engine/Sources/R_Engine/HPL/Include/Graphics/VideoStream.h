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
#ifndef HPL_VIDEO_STREAM_H
#define HPL_VIDEO_STREAM_H

#include "graphics/GraphicsTypes.h"
#include "resources/ResourceBase.h"

namespace hpl {

	//-----------------------------------------

	class iTexture;

	class iVideoStream;

	//-----------------------------------------

	class iVideoStreamLoader
	{
	public:
		virtual ~iVideoStreamLoader(){}

		virtual iVideoStream* Create(const tString& asName)=0;

		tStringVec& GetExtensions(){ return mvExtensions;}
	protected:
		tStringVec mvExtensions;
	};

	//-----------------------------------------

	class iVideoStream : public iResourceBase
	{
	public:
		iVideoStream(tString asName) : iResourceBase(asName,0){}
		virtual ~iVideoStream(){}

		virtual bool LoadFromFile(tString asFilePath)=0;

		virtual void Update(float afTimeStep)=0;

		virtual void Play()=0;
		virtual void Stop()=0;

		virtual void Pause(bool abX)=0;
		virtual bool IsPaused()=0;

		virtual void SetLoop(bool abX)=0;
		virtual bool IsLooping()=0;

		virtual void CopyToTexture(iTexture *apTexture)=0;


		const tString& GetFileName(){return msFilePath;}
		const cVector2l& GetSize(){return mvSize;}

		//////////////////////////////////
		// ResourceBase implementation
		bool Reload(){ return false;}
		void Unload(){}
		void Destroy(){}


	protected:
		tString msFilePath;
		cVector2l mvSize;
	};
};
#endif // HPL_VIDEO_STREAM_H
