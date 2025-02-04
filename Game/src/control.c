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
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "control.h"
#include "display.h"
#include "duke3d.h"
#include "engine.h"
#include "function.h"
#include "joystick.h"
#include "mouse.h"

//***************************************************************************
//
// GLOBALS
//
//***************************************************************************

// FIX_00018: Removed the "smoothmouse" option. This was just a bad fix. Mouse is now faster,
//            smoother.
// extern int32_t g_CV_EnableSmoothMouse;
// extern int32_t g_CV_SmoothMouseSensX;
// extern int32_t g_CV_SmoothMouseSensY;

uint32_t CONTROL_RudderEnabled;
bool CONTROL_MousePresent;
bool CONTROL_JoysPresent[MaxJoys];
bool CONTROL_MouseEnabled;
bool CONTROL_JoystickEnabled;
uint8_t CONTROL_JoystickPort;
uint32_t CONTROL_MouseButtonState1;
uint32_t CONTROL_MouseButtonState2;
// FIX_00019: DigitalAxis Handling now supported. (cool for medkit use)
uint32_t CONTROL_MouseDigitalAxisState1;
uint32_t CONTROL_MouseDigitalAxisState2;
// uint32_t   CONTROL_ButtonHeldState1;
// uint32_t   CONTROL_ButtonHeldState2;
uint32_t CONTROL_JoyButtonState1;
uint32_t CONTROL_JoyButtonState2;

uint32_t CONTROL_JoyHatState1; //[MAXJOYHATS];
uint32_t CONTROL_JoyHatState2; //[MAXJOYHATS];

static int16_t mouseButtons = 0;
static int16_t lastmousebuttons = 0;

static int16_t joyHats[MAXJOYHATS];
static int16_t lastjoyHats[MAXJOYHATS];

static int32_t mousePositionX = 0;
static int32_t mousePositionY = 0;
static int32_t mouseRelativeX = 0;
static int32_t mouseRelativeY = 0;

//***************************************************************************
//
// FUNCTIONS
//
//***************************************************************************

// Joystick/Gamepad bindings
static int32_t JoyAxisMapping[MAXJOYAXES];
static int32_t JoyHatMapping[MAXJOYHATS][8];
static int32_t JoyButtonMapping[MAXJOYBUTTONS];
static float JoyAnalogScale[MAXJOYAXES];
static int32_t JoyAnalogDeadzone[MAXJOYAXES];

int32_t
ACTION(int32_t i)
{

  // Keyboard input
  if ((KB_KeyDown[KeyMapping[i].key1]) ||
      (KB_KeyDown[KeyMapping[i].key2]))
  {
    return 1;
  }

  // Check mouse
  if ((ControllerType == controltype_keyboardandmouse) ||
      (ControllerType == controltype_joystickandmouse))
  {
    // Mouse buttons
    if ((i) > 31)
    {
      if ((CONTROL_MouseButtonState2 >> ((i)-32)) & 1)
      {
        return 1;
      }
    }
    else
    {
      if ((CONTROL_MouseButtonState1 >> (i)) & 1)
      {
        return 1;
      }
    }

    // FIX_00019: DigitalAxis Handling now supported. (cool for medkit use)

    // Mouse Digital Axes
    if ((i) > 31)
    {
      if ((CONTROL_MouseDigitalAxisState2 >> ((i)-32)) & 1)
      {
        return 1;
      }
    }
    else
    {
      if ((CONTROL_MouseDigitalAxisState1 >> (i)) & 1)
      {
        return 1;
      }
    }
  }

  // Check joystick
  if ((ControllerType == controltype_keyboardandjoystick) ||
      (ControllerType == controltype_joystickandmouse))
  {

    if ((i) > 31)
    {
      // Check the joystick
      if ((CONTROL_JoyButtonState2 >> (i - 32)) & 1)
      {
        return 1;
      }

      // Check the hats
      if ((CONTROL_JoyHatState2 >> (i - 32)) & 1)
      {
        return 1;
      }
    }
    else
    {
      if ((CONTROL_JoyButtonState1 >> i) & 1)
      {
        return 1;
      }

      // Check the hats
      if ((CONTROL_JoyHatState1 >> i) & 1)
      {
        return 1;
      }
    }
  }

  return 0;
}

int32_t
RESET_ACTION(int32_t i)
{
  KB_KeyDown[KeyMapping[i].key1] = 0;
  KB_KeyDown[KeyMapping[i].key2] = 0;

  return 0;
}

static void
SETMOUSEBUTTON(int32_t i)
{

  // CONTROL_MouseButtonState1 |= (1<<i);

  int32_t b;

  if (i < 32)
  {
    b = 1 << i;

    CONTROL_MouseButtonState1 |= b;
  }
  else
  {
    i -= 32;

    b = 1 << i;

    CONTROL_MouseButtonState2 |= b;
  }
}

void
RESMOUSEBUTTON(int32_t i)
{

  // CONTROL_MouseButtonState1 &= ~(1<<i);

  int32_t b;

  if (i < 32)
  {
    b = 1 << i;

    CONTROL_MouseButtonState1 &= ~b;
  }
  else
  {
    i -= 32;

    b = 1 << i;

    CONTROL_MouseButtonState2 &= ~b;
  }
}

// FIX_00019: DigitalAxis Handling now supported. (cool for medkit use)

void
SETMOUSEDIGITALAXIS(int32_t i)
{

  int32_t b;

  if (i < 0)
    return;

  if (i < 32)
  {
    b = 1 << i;
    CONTROL_MouseDigitalAxisState1 |= b;
  }
  else
  {
    i -= 32;
    b = 1 << i;
    CONTROL_MouseDigitalAxisState2 |= b;
  }
}

void
RESMOUSEDIGITALAXIS(int32_t i)
{

  int32_t b;

  if (i < 0)
    return;

  if (i < 32)
  {
    b = 1 << i;
    CONTROL_MouseDigitalAxisState1 &= ~b;
  }
  else
  {
    i -= 32;
    b = 1 << i;
    CONTROL_MouseDigitalAxisState2 &= ~b;
  }
}

static void
SETJOYBUTTON(int32_t i)
{
  // CONTROL_JoyButtonState |= (1<<i);
  int32_t b;

  if (i < 32)
  {
    b = 1 << i;

    CONTROL_JoyButtonState1 |= b;
  }
  else
  {
    i -= 32;

    b = 1 << i;

    CONTROL_JoyButtonState2 |= b;
  }
}
static void
RESJOYBUTTON(int32_t i)
{
  int32_t b;

  if (i < 32)
  {
    b = 1 << i;

    CONTROL_JoyButtonState1 &= ~b;
  }
  else
  {
    i -= 32;

    b = 1 << i;

    CONTROL_JoyButtonState2 &= ~b;
  }
}

static void
SETHATBUTTON(int32_t i)
{
  // CONTROL_JoyHatState1 |= (1<<i);

  int32_t b;

  if (i < 32)
  {
    b = 1 << i;

    CONTROL_JoyHatState1 |= b;
  }
  else
  {
    i -= 32;

    b = 1 << i;

    CONTROL_JoyHatState2 |= b;
  }
}

static void
RESHATBUTTON(int32_t i)
{

  // CONTROL_JoyHatState1 &= ~(1<<i);
  int32_t b;

  if (i < 32)
  {
    b = 1 << i;

    CONTROL_JoyHatState1 &= ~b;
  }
  else
  {
    i -= 32;

    b = 1 << i;

    CONTROL_JoyHatState2 &= ~b;
  }
}

void
CONTROL_UpdateKeyboardState(int32_t key, int32_t pressed)
{
  /*

          if(pressed)
          {
                  CONTROL_KeyStates[key] = 1;
          }
          else
          {
                  CONTROL_KeyStates[key] = 0;
          }
          */
  /*
  int32_t i;

  for (i = 0; i < MAXGAMEBUTTONS; i++)
  {
          if (KeyMapping[i].key_active == false)
          {
                  continue;
          }

          if (KeyMapping[i].key1 == key ||
                  KeyMapping[i].key2 == key)
          {

                  if (pressed)
                  {
                          SETBUTTON(i);
                  }
                  else
                  {
                          RESBUTTON(i);
                  }
          }
  }
  */
}

void
CONTROL_MapKey(int32_t which, kb_scancode key1, kb_scancode key2)
{
  // FIX_00020: Protect you from assigning a function to the ESC key through duke3d.cfg
  if (key1 == sc_Escape || key2 == sc_Escape)
  {
    if (key1 == sc_Escape)
      key1 = 0;
    else
      key2 = 0;

    printf("Discarding ESCAPE key for function : %s\n", gamefunctions[which]);
  }

  if (key1 || key2)
    KeyMapping[which].key_active = true;
  else
    KeyMapping[which].key_active = false;

  KeyMapping[which].key1 = key1;
  KeyMapping[which].key2 = key2;
}

void
CONTROL_MapButton(
  int32_t whichfunction,
  int32_t whichbutton,
  bool clicked_or_doubleclicked)
{
  if (clicked_or_doubleclicked)
    return; // TODO

  if (whichbutton < 0 || whichbutton >= MAXMOUSEBUTTONS)
    return;

  MouseMapping[whichbutton] = whichfunction;
}

void
CONTROL_MapJoyButton(int32_t whichfunction, int32_t whichbutton, bool doubleclicked)
{
  if (whichbutton < 0 || whichbutton >= MAXJOYBUTTONS)
  {
    return;
  }

  if (doubleclicked)
    return; // TODO

  JoyButtonMapping[whichbutton] = whichfunction;
}

void
CONTROL_MapJoyHat(int32_t whichfunction, int32_t whichhat, int32_t whichvalue)
{
  if (whichhat < 0 || whichhat >= MAXJOYHATS)
  {
    return;
  }

  JoyHatMapping[whichhat][whichvalue] = whichfunction;
}

void
CONTROL_DefineFlag(int32_t which, bool toggle)
{
  // STUBBED("CONTROL_DefineFlag");
}

bool
CONTROL_FlagActive(int32_t which)
{
  STUBBED("CONTROL_FlagActive");
  return false;
}

void
CONTROL_ClearAssignments(void)
{
  STUBBED("CONTROL_ClearAssignments");
}

void
CONTROL_GetUserInput(UserInput* info)
{
  STUBBED("CONTROL_GetUserInput");
}

void
CONTROL_GetInput(ControlInfo* info)
{
  int32_t sens_X = CONTROL_GetMouseSensitivity_X();
  int32_t sens_Y = CONTROL_GetMouseSensitivity_Y();
  int32_t mx = 0, my = 0;
  int32_t i, j;

  memset(info, '\0', sizeof(ControlInfo));

  // info->dx = info->dz = 0;

  _handle_events(); // get the very last mouse position before reading it.
  MOUSE_GetDelta(&mx, &my);

  // GetCursorPos(&point);
  //	SDL_GetMouseState(&x, &y);
  //	SDL_WarpMouse(160, 100);
  // mx = (-xx+point.x)<<2;
  // my = (-yy+point.y)<<2;
  // xx=point.x; yy=point.y;

  info->dyaw = (mx * sens_X);

  switch (ControllerType)
  {
    case controltype_keyboardandjoystick:
    {
    }
    break;

    case controltype_joystickandmouse:
      // Not sure what I was thinking here...
      // Commented this out because it totally breaks smooth mouse etc...
      /*
      {
              // Mouse should use pitch instead of forward movement.
              info->dpitch = my * sens*2;
      }
      break;
      */

    default:
    {
      // If mouse aim is active
      if (myaimmode)
      {
        // FIX_00052: Y axis for the mouse is now twice as sensitive as before
        info->dpitch = (my * sens_Y * 2);
      }
      else
      {
        info->dz = (my * sens_Y * 2);
      }
    }
    break;
  }

  // TODO: releasing the mouse button does not honor if a keyboard key with
  // the same function is still pressed. how should it?
  for (i = 0; i < MAXMOUSEBUTTONS; ++i)
  {
    if (MouseMapping[i] != -1)
    {
      if (!(lastmousebuttons & (1 << i)) && mouseButtons & (1 << i))
      {
        SETMOUSEBUTTON(MouseMapping[i]); // MouseMapping[i]
        // printf("mouse button: %d\n", i);
      }
      else if (lastmousebuttons & (1 << i) && !(mouseButtons & (1 << i)))
      {
        RESMOUSEBUTTON(MouseMapping[i]); // MouseMapping[i]
      }
    }
  }
  lastmousebuttons = mouseButtons;

  // FIX_00019: DigitalAxis Handling now supported. (cool for medkit use)
  // update digital axis
  RESMOUSEDIGITALAXIS(MouseDigitalAxeMapping[0][0]);
  RESMOUSEDIGITALAXIS(MouseDigitalAxeMapping[0][1]);
  RESMOUSEDIGITALAXIS(MouseDigitalAxeMapping[1][0]);
  RESMOUSEDIGITALAXIS(MouseDigitalAxeMapping[1][1]);

  if (mx < 0)
  {
    SETMOUSEDIGITALAXIS(MouseDigitalAxeMapping[0][0]);
  }
  else if (mx > 0)
  {
    SETMOUSEDIGITALAXIS(MouseDigitalAxeMapping[0][1]);
  }

  if (my < 0)
  {
    SETMOUSEDIGITALAXIS(MouseDigitalAxeMapping[1][0]);
  }
  else if (my > 0)
  {
    SETMOUSEDIGITALAXIS(MouseDigitalAxeMapping[1][1]);
  }

  // update stick state.
  if ((CONTROL_JoystickEnabled) && (_joystick_update()))
  {

    // Check the hats
    JOYSTICK_UpdateHats();

    // TODO: make this NOT use the BUTTON() system for storing the hat input. (requires much game code changing)
    for (i = 0; i < MAXJOYHATS; i++)
    {

      for (j = 0; j < 8; j++)
      {
        if (!(lastjoyHats[i] & (1 << j)) && (joyHats[i] & (1 << j)))
        {
          SETHATBUTTON(JoyHatMapping[i][j]);
        }
        else if ((lastjoyHats[i] & (1 << j)) && !(joyHats[i] & (1 << j)))
        {
          RESHATBUTTON(JoyHatMapping[i][j]);
        }
      }

      lastjoyHats[i] = joyHats[i];
    }

    for (i = 0; i < MAXJOYAXES; i++)
    {
      switch (JoyAxisMapping[i])
      {
        case analog_turning:
        {
          info->dyaw += (int32_t)((float)CONTROL_FilterDeadzone(
                                    _joystick_axis(i),
                                    JoyAnalogDeadzone[i]) *
                                  JoyAnalogScale[i]);
        }
        break;
        case analog_strafing:
        {
          info->dx += (int32_t)((float)CONTROL_FilterDeadzone(
                                  _joystick_axis(i),
                                  JoyAnalogDeadzone[i]) *
                                JoyAnalogScale[i]);
          // printf("Joy %d = %d\n", i, info->dx);
        }
        break;
        case analog_lookingupanddown:
          info->dpitch += (int32_t)((float)CONTROL_FilterDeadzone(
                                      _joystick_axis(i),
                                      JoyAnalogDeadzone[i]) *
                                    JoyAnalogScale[i]);
          break;
        case analog_elevation: // STUB
          break;
        case analog_rolling: // STUB
          break;
        case analog_moving:
        {
          info->dz += (int32_t)((float)CONTROL_FilterDeadzone(
                                  _joystick_axis(i),
                                  JoyAnalogDeadzone[i]) *
                                JoyAnalogScale[i]);
        }
        break;
        default:
          break;
      }
    }

    // !!! FIXME: Do this.
    // SETBUTTON based on _joystick_button().
    for (i = 0; i < MAXJOYBUTTONS; ++i)
    {
      if (_joystick_button(i))
      {
        SETJOYBUTTON(JoyButtonMapping[i]);
      }
      else
      {
        RESJOYBUTTON(JoyButtonMapping[i]);
      }
    }
  }
}

void
CONTROL_ClearAction(int32_t whichbutton)
{
  // RESBUTTON(whichbutton);
  KB_KeyDown[KeyMapping[whichbutton].key1] = 0;
  KB_KeyDown[KeyMapping[whichbutton].key2] = 0;

  RESJOYBUTTON(whichbutton);
  RESHATBUTTON(whichbutton);

  RESMOUSEDIGITALAXIS(whichbutton);
}

void
CONTROL_ClearUserInput(UserInput* info)
{
  STUBBED("CONTROL_ClearUserInput");
}

void
CONTROL_WaitRelease(void)
{
  STUBBED("CONTROL_WaitRelease");
}

void
CONTROL_Ack(void)
{
  STUBBED("CONTROL_Ack");
}

void
CONTROL_CenterJoystick(
  void (*CenterCenter)(void),
  void (*UpperLeft)(void),
  void (*LowerRight)(void),
  void (*CenterThrottle)(void),
  void (*CenterRudder)(void))
{
  STUBBED("CONTROL_CenterJoystick");
}

int32_t
CONTROL_GetMouseSensitivity_X(void)
{
  return mouseSensitivity_X;
}

void
CONTROL_SetMouseSensitivity_X(int32_t newsensitivity)
{
  mouseSensitivity_X = newsensitivity;
}

// FIX_00014: Added Y cursor setup for mouse sensitivity in the menus
int32_t
CONTROL_GetMouseSensitivity_Y(void)
{
  return mouseSensitivity_Y;
}

void
CONTROL_SetMouseSensitivity_Y(int32_t newsensitivity)
{
  mouseSensitivity_Y = newsensitivity;
}

void
CONTROL_Startup(
  controltype which,
  int32_t (*TimeFunction)(void),
  int32_t ticspersecond)
{
  int32_t i;

  // Init the joystick
  _joystick_init();

  for (i = 0; i < MAXJOYHATS; i++)
  {
    joyHats[i] = 0;
    lastjoyHats[i] = 0;
  }

  CONTROL_MouseButtonState1 = 0;
  CONTROL_MouseButtonState2 = 0;
  CONTROL_MouseDigitalAxisState1 = 0;
  CONTROL_MouseDigitalAxisState2 = 0;
  CONTROL_JoyButtonState1 = 0;
  CONTROL_JoyButtonState2 = 0;
  CONTROL_JoyHatState1 = 0;
  CONTROL_JoyHatState2 = 0;
}

void
CONTROL_Shutdown(void)
{
  _joystick_deinit();
}

void
CONTROL_MapAnalogAxis(
  int32_t whichaxis,
  int32_t whichanalog)
{
  // STUBBED("CONTROL_MapAnalogAxis");
  if (whichaxis < MAXJOYAXES)
  {
    JoyAxisMapping[whichaxis] = whichanalog;
  }
}

// FIX_00019: DigitalAxis Handling now supported. (cool for medkit use)
void
CONTROL_MapDigitalAxis(
  int32_t whichaxis,
  int32_t whichfunction,
  int32_t direction)
{
  if (whichaxis < 0 || whichaxis >= MAXMOUSEAXES || direction < 0 || direction >= 2)
    return;

  MouseDigitalAxeMapping[whichaxis][direction] = whichfunction;
}

void
CONTROL_SetAnalogAxisScale(
  int32_t whichaxis,
  float axisscale)
{
  if (whichaxis < MAXJOYAXES)
  {
    // Set it... make sure we don't let them set it to 0.. div by 0 is bad.
    JoyAnalogScale[whichaxis] = (axisscale == 0) ? 1.0f : axisscale;
  }
}

void
CONTROL_SetAnalogAxisDeadzone(
  int32_t whichaxis,
  int32_t axisdeadzone)
{
  if (whichaxis < MAXJOYAXES)
  {
    // Set it...
    JoyAnalogDeadzone[whichaxis] = axisdeadzone;
  }
}

int32_t
CONTROL_FilterDeadzone(
  int32_t axisvalue,
  int32_t axisdeadzone)
{
  if ((axisvalue < axisdeadzone) && (axisvalue > -axisdeadzone))
  {
    return 0;
  }

  return axisvalue;
}

int32_t
CONTROL_GetFilteredAxisValue(int32_t axis)
{
  return (int32_t)((float)CONTROL_FilterDeadzone(
                     _joystick_axis(axis),
                     JoyAnalogDeadzone[axis]) *
                   JoyAnalogScale[axis]);
}

void
CONTROL_PrintAxes(void)
{
  STUBBED("CONTROL_PrintAxes");
}

bool
MOUSE_Init(void)
{
  memset(MouseMapping, -1, sizeof(MouseMapping));
  memset(MouseDigitalAxeMapping, -1, sizeof(MouseDigitalAxeMapping));
  return true;
}

void
MOUSE_Shutdown(void)
{
  STUBBED("MOUSE_Shutdown");
}

void
MOUSE_ShowCursor(void)
{
  STUBBED("MOUSE_ShowCursor");
}

void
MOUSE_HideCursor(void)
{
  STUBBED("MOUSE_HideCursor");
}

static void
updateMouse(void)
{
  // this is in buildengine.
  int16_t x, y;
  getmousevalues(&x, &y, &mouseButtons);

  mouseRelativeX += x;
  mouseRelativeY += y;
  mousePositionX += x;
  mousePositionY += y;
}

int32_t
MOUSE_GetButtons(void)
{
  // updateMouse();
  return ((int32_t)mouseButtons);
}

void
MOUSE_GetPosition(int32_t* x, int32_t* y)
{
  if (x)
    *x = mousePositionX;
  if (y)
    *y = mousePositionY;
}

void
MOUSE_GetDelta(int32_t* x, int32_t* y)
{
  updateMouse();

  if (x)
    *x = mouseRelativeX;
  if (y)
    *y = mouseRelativeY;

  mouseRelativeX = 0;
  mouseRelativeY = 0;
}

void
JOYSTICK_UpdateHats()
{
  int32_t i;

  for (i = 0; i < MAXJOYHATS; i++)
  {
    // for(j=0; j<8; j++)
    //{
    joyHats[i] = _joystick_hat(i);
    //}
  }
}
