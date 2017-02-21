/* ****************************************************************************
 *
 * Copyright (c) Microsoft Corporation. All rights reserved. 
 *
 *
 * This file is part of Microsoft R Host.
 * 
 * Microsoft R Host is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Microsoft R Host is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Microsoft R Host.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ***************************************************************************/

#include "stdafx.h"

#ifdef _WIN32
#include "msvcrt.h"

#define MSVCRT_EXPORT(name) \
    decltype(name) name = reinterpret_cast<decltype(name)>(GetProcAddress(get_msvcrt(), #name))

namespace rhost {
    namespace msvcrt {
        namespace {
            HMODULE get_msvcrt() {
                static HMODULE msvcrt = LoadLibraryEx(L"msvcrt.dll", NULL, LOAD_LIBRARY_SEARCH_SYSTEM32);
                return msvcrt;
            }
        }

        MSVCRT_EXPORT(calloc);
        MSVCRT_EXPORT(malloc);
        MSVCRT_EXPORT(free);
        MSVCRT_EXPORT(atexit);
        MSVCRT_EXPORT(vsnprintf);
        MSVCRT_EXPORT(mbstowcs);
        MSVCRT_EXPORT(wctomb);
        MSVCRT_EXPORT(mbtowc);
    }
}

#endif
