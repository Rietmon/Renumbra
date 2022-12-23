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
#ifndef HPL_CONFIGFILE_H
#define HPL_CONFIGFILE_H

#include "system/SystemTypes.h"

class TiXmlDocument;
class cFileSearcher;

namespace hpl {

	class cConfigFile
	{
	public:
		cConfigFile(tWString asFile);
		~cConfigFile();

		/**
		 * Loads data from file
		 * \return true if loading ws ok, else false
		 */
		bool Load();
		/**
		 * Saves the data to file
		 * \return true if loading ws ok, else false
		 */
		bool Save();

		void SetString(tString asLevel, tString asName, tString asVal);
		void SetInt(tString asLevel, tString asName, int alVal);
		void SetFloat(tString asLevel, tString asName, float afVal);
		void SetBool(tString asLevel, tString asName, bool abVal);

		tString GetString(tString asLevel, tString asName, tString asDefault);
		int GetInt(tString asLevel, tString asName, int alDefault);
		float GetFloat(tString asLevel, tString asName, float afDefault);
		bool GetBool(tString asLevel, tString asName, bool abDefault);

	private:
		tWString msFile;
		cFileSearcher *mpFileSearcher;

		TiXmlDocument *mpXmlDoc;

		const char* GetCharArray(tString asLevel, tString asName);
	};

};
#endif // HPL_CONFIGFILE_H
