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

// scriplib.h

#ifndef _scriplib_public
#define _scriplib_public

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /*
  ==============
  =
  = SCRIPT_Init
  =
  ==============
  */
  int32_t SCRIPT_Init(uint8_t* name);

  /*
  ==============
  =
  = SCRIPT_Free
  =
  ==============
  */
  void SCRIPT_Free(int32_t scripthandle);

  /*
  ==============
  =
  = SCRIPT_Parse
  =
  ==============
  */

  int32_t SCRIPT_Parse(uint8_t* data, int32_t length, char* name);

  /*
  ==============
  =
  = SCRIPT_Load
  =
  ==============
  */

  int32_t SCRIPT_Load(char* filename);

  /*
  ==============
  =
  = SCRIPT_Save
  =
  ==============
  */
  void SCRIPT_Save(int32_t scripthandle, char* filename);

  /*
  ==============
  =
  = SCRIPT_NumberSections
  =
  ==============
  */

  int32_t SCRIPT_NumberSections(int32_t scripthandle);

  /*
  ==============
  =
  = SCRIPT_Section
  =
  ==============
  */

  uint8_t* SCRIPT_Section(int32_t scripthandle, int32_t which);

  /*
  ==============
  =
  = SCRIPT_NumberEntries
  =
  ==============
  */

  int32_t SCRIPT_NumberEntries(int32_t scripthandle, char* sectionname);

  /*
  ==============
  =
  = SCRIPT_Entry
  =
  ==============
  */

  char* SCRIPT_Entry(int32_t scripthandle, char* sectionname, int32_t which);

  /*
  ==============
  =
  = SCRIPT_GetRaw
  =
  ==============
  */
  char* SCRIPT_GetRaw(int32_t scripthandle, char* sectionname, char* entryname);

  /*
  ==============
  =
  = SCRIPT_GetString
  =
  ==============
  */
  void SCRIPT_GetString(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    char* dest);

  /*
  ==============
  =
  = SCRIPT_GetDoubleString
  =
  ==============
  */
  void SCRIPT_GetDoubleString(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    char* dest1,
    char* dest2);

  /*
  ==============
  =
  = SCRIPT_GetNumber
  =
  ==============
  */
  bool SCRIPT_GetNumber(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    int32_t* number);

  /*
  ==============
  =
  = SCRIPT_GetBoolean
  =
  ==============
  */
  void SCRIPT_GetBoolean(
    int32_t scripthandle,
    uint8_t* sectionname,
    uint8_t* entryname,
    bool* boolean);

  /*
  ==============
  =
  = SCRIPT_GetFloat
  =
  ==============
  */

  bool SCRIPT_GetFloat(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    float* floatnumber);

  /*
  ==============
  =
  = SCRIPT_GetDouble
  =
  ==============
  */

  void SCRIPT_GetDouble(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    double* number);

  /*
  ==============
  =
  = SCRIPT_PutComment
  =
  ==============
  */
  void SCRIPT_PutComment(int32_t scripthandle, uint8_t* sectionname, uint8_t* comment);

  /*
  ==============
  =
  = SCRIPT_PutEOL
  =
  ==============
  */
  void SCRIPT_PutEOL(int32_t scripthandle, uint8_t* sectionname);

  /*
  ==============
  =
  = SCRIPT_PutMultiComment
  =
  ==============
  */
  void SCRIPT_PutMultiComment(
    int32_t scripthandle,
    uint8_t* sectionname,
    uint8_t* comment,
    ...);

  /*
  ==============
  =
  = SCRIPT_PutSection
  =
  ==============
  */
  void SCRIPT_PutSection(int32_t scripthandle, uint8_t* sectionname);

  /*
  ==============
  =
  = SCRIPT_PutRaw
  =
  ==============
  */
  void SCRIPT_PutRaw(
    int32_t scripthandle,
    uint8_t* sectionname,
    uint8_t* entryname,
    uint8_t* raw);

  /*
  ==============
  =
  = SCRIPT_PutString
  =
  ==============
  */
  void SCRIPT_PutString(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    char* string);

  /*
  ==============
  =
  = SCRIPT_PutDoubleString
  =
  ==============
  */
  void SCRIPT_PutDoubleString(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    char* string1,
    char* string2);

  /*
  ==============
  =
  = SCRIPT_PutNumber
  =
  ==============
  */
  void SCRIPT_PutNumber(
    int32_t scripthandle,
    char* sectionname,
    char* entryname,
    int32_t number,
    bool hexadecimal,
    bool defaultvalue);

  /*
  ==============
  =
  = SCRIPT_PutBoolean
  =
  ==============
  */
  void SCRIPT_PutBoolean(
    int32_t scripthandle,
    uint8_t* sectionname,
    uint8_t* entryname,
    bool boolean);

  /*
  ==============
  =
  = SCRIPT_PutDouble
  =
  ==============
  */

  void SCRIPT_PutDouble(
    int32_t scripthandle,
    uint8_t* sectionname,
    uint8_t* entryname,
    double number,
    bool defaultvalue);

#ifdef __cplusplus
};
#endif
#endif
