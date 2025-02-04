//-------------------------------------------------------------------------
/*
Copyright (C) 1996, 2003 - 3D Realms Entertainment

This file is part of Duke Nukem 3D version 1.5 - Atomic Edition

Duke Nukem 3D is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
aint32_t with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Original Source: 1996 - Todd Replogle
Prepared for public release: 03/21/2003 - Charlie Wiederhold, 3D Realms
*/
//-------------------------------------------------------------------------

//***************************************************************************
//
//    UTIL_LIB.C - various utils
//
//***************************************************************************

#include <stdint.h>

#ifndef _util_lib_public
#define _util_lib_public

#ifdef __cplusplus
extern "C"
{
#endif

  extern int32_t _argc;
  extern char** _argv;

  void RegisterShutdownFunction(void (*shutdown)(void));
  void Error(int errorType, const char* error, ...);

  uint8_t CheckParm(char* check);

  void* SafeMalloc(int32_t size);
  int32_t SafeMallocSize(void* ptr);
  void SafeFree(void* ptr);
  void SafeRealloc(void** ptr, int32_t newsize);
  int32_t ParseHex(uint8_t* hex);
  int32_t ParseNum(uint8_t* str);
  int16_t MotoShort(int16_t l);
  int16_t IntelShort(int16_t l);
  int32_t Motoint32_t(int32_t l);
  int32_t Intelint32_t(int32_t l);

  void HeapSort(uint8_t* base, int32_t nel, int32_t width, int32_t (*compare)(), void (*switcher)());

#ifdef __cplusplus
};
#endif

#endif
