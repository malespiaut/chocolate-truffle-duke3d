/*
Copyright (C) 1994-1995 Apogee Software, Ltd.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/
/**********************************************************************
   module: DPMI.C

   author: James R. Dose
   date:   April 8, 1994

   Functions for performing DPMI calls.

   (c) Copyright 1994 James R. Dose.  All Rights Reserved.
**********************************************************************/

#include "dpmi.h"
#include <stdlib.h>

int
DPMI_GetDOSMemory(void** ptr, void** descriptor, unsigned length)
{
  *ptr = malloc(length);
  *descriptor = *ptr;

  return (descriptor == 0) ? DPMI_Error : DPMI_Ok;
}

int
DPMI_FreeDOSMemory(void* descriptor)
{
  free(descriptor);

  return (descriptor == 0) ? DPMI_Error : DPMI_Ok;
}
