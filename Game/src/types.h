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

#ifndef _types_public
#define _types_public

#include <inttypes.h>

#ifdef __cplusplus
extern "C"
{
#endif

//***************************************************************************
//
//  BYTE ACCESS MACROS
//
//***************************************************************************

// WORD macros
#define Int16_HighByte(x) ((uint8)((x) >> 8))
#define Int16_LowByte(x) ((uint8)((x)&0xff))

// DWORD macros
#define Int32_4Byte(x) ((uint8)((x) >> 24) & 0xff)
#define Int32_3Byte(x) ((uint8)(((x) >> 16) & 0xff))
#define Int32_2Byte(x) ((uint8)(((x) >> 8) & 0xff))
#define Int32_1Byte(x) ((uint8)((x)&0xff))

#ifdef __NeXT__
#define stricmp strcasecmp
#define strcmpi strcasecmp
#endif

#ifdef __cplusplus
};
#endif
#endif
