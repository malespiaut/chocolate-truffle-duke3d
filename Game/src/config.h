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

#ifndef _config_public
#define _config_public

#include <stdint.h>

#define SETUPNAMEPARM "SETUPFILE"
#define COMMMACRO "CommbatMacro# "

extern int32_t ControllerType;
extern int32_t MouseAiming;
extern int32_t ScreenWidth;
extern int32_t ScreenHeight;
extern int32_t FullScreen;

void CONFIG_ReadSetup(void);
void CONFIG_GetSetupFilename(void);
void CONFIG_WriteSetup(void);

#endif
