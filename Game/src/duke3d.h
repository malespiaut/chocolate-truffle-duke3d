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
#ifndef _INCL_DUKE3D_H_
#define _INCL_DUKE3D_H_

#include "build.h"

#if (!defined MAX_PATH)
#if (defined MAXPATHLEN)
#define MAX_PATH MAXPATHLEN
#elif (defined PATH_MAX)
#define MAX_PATH PATH_MAX
#else
#define MAX_PATH 256
#endif
#endif

#if UNIX
#include "dukeunix.h"
#endif

#if PLATFORM_MACOSX
#include "dukeunix.h"
#endif

#if WIN32
#include "dukewin.h"
#endif

//  FIX_00022: Automatically recognize the shareware grp (v1.3) + full version (1.3d) +
//             atomic (1.4/1.5 grp) and the con files version (either 1.3 or 1.4) (JonoF's idea)

extern uint8_t conVersion;
extern uint8_t grpVersion;

#define RANCID_ID 1
#define XDUKE_ID 2
#define JONOF_ID 3

// Chocolate DukeNukem3D is a fork of xDuke v17.9

#define DUKE_ID XDUKE_ID
#define CHOCOLATE_DUKE_REV_X 1
#define CHOCOLATE_DUKE_REV_DOT_Y 0 // rev is: CHOCOLATE_DUKE_REV_X.CHOCOLATE_DUKE_REV_DOT_Y

#define MAX_KNOWN_GRP 4

enum
{
  UNKNOWN_GRP = 0,
  SHAREWARE_GRP13,
  REGULAR_GRP13D,
  ATOMIC_GRP14_15,
  DUKEITOUTINDC_GRP
};

#define CRC_BASE_GRP_SHAREWARE_13 0x983AD923
#define CRC_BASE_GRP_FULL_13 0xBBC9CE44
#define CRC_BASE_GRP_PLUTONIUM_14 0xF514A6AC
#define CRC_BASE_GRP_ATOMIC_15 0xFD3DCFF1

// implies  conVersion == 14 or conVersion == 15
#define PLUTOPAK (!VOLUMEONE && !VOLUMEALL)
#define VOLUMEONE (getGRPcrc32(0) == CRC_BASE_GRP_SHAREWARE_13)
// VOLUMEALL = 1.3d full
#define VOLUMEALL (getGRPcrc32(0) == CRC_BASE_GRP_FULL_13 || (conVersion == 13 && getGRPcrc32(0) != CRC_BASE_GRP_SHAREWARE_13 && getGRPcrc32(0) != CRC_BASE_GRP_PLUTONIUM_14 && getGRPcrc32(0) != CRC_BASE_GRP_ATOMIC_15))

#define SCREENSHOTPATH "screenshots"

// #define TEN
// #define BETA

// #define AUSTRALIA

#define MAXSLEEPDIST 16384
#define SLEEPTIME 24 * 64

extern int32_t BYTEVERSION;

extern int32_t BYTEVERSION_27;
extern int32_t BYTEVERSION_28;
extern int32_t BYTEVERSION_29; // really needed???
extern int32_t BYTEVERSION_116;
extern int32_t BYTEVERSION_117;
extern int32_t BYTEVERSION_118;
extern int32_t BYTEVERSION_1_3;

#define NUMPAGES 1

#define AUTO_AIM_ANGLE 48
#define RECSYNCBUFSIZ 2520 // 2520 is the (LCM of 1-8)*3
#define MOVEFIFOSIZ 256

#define FOURSLEIGHT (1 << 8)

struct player_struct;

#include "../../Game/src/types.h"
#include "gamedefs.h"

// #define TICRATE (120)
// #define TICSPERFRAME (TICRATE/26)

extern int32_t g_iTickRate;
extern int32_t g_iTicksPerFrame;

#define TICRATE g_iTickRate
#define TICSPERFRAME (TICRATE / g_iTicksPerFrame)

// #define GC (TICSPERFRAME*44)

#define NUM_SOUNDS 450

#define ALT_IS_PRESSED (KB_KeyPressed(sc_RightAlt) || KB_KeyPressed(sc_LeftAlt))
#define SHIFTS_IS_PRESSED (KB_KeyPressed(sc_RightShift) || KB_KeyPressed(sc_LeftShift))
#define RANDOMSCRAP EGS(s->sectnum, s->x + (TRAND & 255) - 128, s->y + (TRAND & 255) - 128, s->z - (8 << 8) - (TRAND & 8191), SCRAP6 + (TRAND & 15), -8, 48, 48, TRAND & 2047, (TRAND & 63) + 64, -512 - (TRAND & 2047), i, 5)

#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKCYAN 3
#define DARKRED 4
#define DARKPURPLE 5
#define BROWN 6
#define LIGHTGRAY 7

#define DARKGRAY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define PURPLE 13
#define YELLOW 14
#define WHITE 15

#define PHEIGHT (38 << 8)

#define WAIT(X)                   \
  ototalclock = totalclock + (X); \
  while (totalclock < ototalclock)

#define MODE_MENU 1
#define MODE_DEMO 2
#define MODE_GAME 4
#define MODE_EOL 8
#define MODE_TYPE 16
#define MODE_RESTART 32
#define MODE_SENDTOWHOM 64
#define MODE_END 128

#define MAXANIMWALLS 512
#define MAXINTERPOLATIONS 2048
#define NUMOFFIRSTTIMEACTIVE 192

#define MAXCYCLERS 256
#define MAXSCRIPTSIZE 20460
#define MAXANIMATES 64

#define SP sprite[i].yvel
#define SX sprite[i].x
#define SY sprite[i].y
#define SZ sprite[i].z
#define SS sprite[i].shade
#define PN sprite[i].picnum
#define SA sprite[i].ang
#define SV sprite[i].xvel
#define ZV sprite[i].zvel
#define RX sprite[i].xrepeat
#define RY sprite[i].yrepeat
#define OW sprite[i].owner
#define CS sprite[i].cstat
#define SH sprite[i].extra
#define CX sprite[i].xoffset
#define CY sprite[i].yoffset
#define CD sprite[i].clipdist
#define PL sprite[i].pal
#define SLT sprite[i].lotag
#define SHT sprite[i].hitag
#define SECT sprite[i].sectnum

#define face_player 1
#define geth 2
#define getv 4
#define random_angle 8
#define face_player_slow 16
#define spin 32
#define face_player_smart 64
#define fleeenemy 128
#define jumptoplayer 257
#define seekplayer 512
#define furthestdir 1024
#define dodgebullet 4096

#define TRAND krand()

#define MAX_WEAPONS 12

#define KNEE_WEAPON 0
#define PISTOL_WEAPON 1
#define SHOTGUN_WEAPON 2
#define CHAINGUN_WEAPON 3
#define RPG_WEAPON 4
#define HANDBOMB_WEAPON 5
#define SHRINKER_WEAPON 6
#define DEVISTATOR_WEAPON 7
#define TRIPBOMB_WEAPON 8
#define FREEZE_WEAPON 9
#define HANDREMOTE_WEAPON 10
#define GROW_WEAPON 11

#define T1 hittype[i].temp_data[0]
#define T2 hittype[i].temp_data[1]
#define T3 hittype[i].temp_data[2]
#define T4 hittype[i].temp_data[3]
#define T5 hittype[i].temp_data[4]
#define T6 hittype[i].temp_data[5]

#define IFWITHIN(B, E) if ((PN) >= (B) && (PN) <= (E))
#define KILLIT(KX)    \
  {                   \
    deletesprite(KX); \
    goto BOLT;        \
  }

#define IFMOVING if (ssp(i, CLIPMASK0))
#define IFHIT           \
  j = ifhitbyweapon(i); \
  if (j >= 0)
#define IFHITSECT               \
  j = ifhitsectors(s->sectnum); \
  if (j >= 0)

#define AFLAMABLE(X) (X == BOX || X == TREE1 || X == TREE2 || X == TIRE || X == CONE)

#define IFSKILL1 if (player_skill < 1)
#define IFSKILL2 if (player_skill < 2)
#define IFSKILL3 if (player_skill < 3)
#define IFSKILL4 if (player_skill < 4)

#define rnd(X) ((TRAND >> 8) >= (255 - (X)))

typedef struct
{
  int16_t i;
  int32_t voice;
} SOUNDOWNER;

#include "audiolib/usrhooks.h"
/*


#define __USRHOOKS_H

enum USRHOOKS_Errors
   {
   USRHOOKS_Warning = -2,
   USRHOOKS_Error   = -1,
   USRHOOKS_Ok      = 0
   };
*/

#pragma pack(push)
#pragma pack(1)

typedef struct
{
  int8_t avel, horz;
  int16_t fvel, svel;
  uint32_t bits;
} input;

#pragma pack(pop)

/* !!! FIXME: "sync" is defined in unistd.h ... :(  --ryan. */
#define sync duke_sync
extern input inputfifo[MOVEFIFOSIZ][MAXPLAYERS], sync[MAXPLAYERS];
extern input recsync[RECSYNCBUFSIZ];

extern int32_t movefifosendplc;

typedef struct
{
  uint8_t* ptr;
  volatile uint8_t lock; // tanguyf: if not volatile, the game can go into an infinite loop in optimised mode
  int32_t length, num;
} SAMPLE;

struct animwalltype
{
  int16_t wallnum;
  int32_t tag;
};
extern struct animwalltype animwall[MAXANIMWALLS];
extern int16_t numanimwalls, probey, lastprobey;

char* mymembuf;
extern uint8_t typebuflen;
char typebuf[41];
extern uint8_t MusicPtr[72000];
extern int32_t msx[2048], msy[2048];
extern int16_t cyclers[MAXCYCLERS][6], numcyclers;
extern char myname[2048];

#pragma pack(push, 4)
struct user_defs
{
  uint8_t god, warp_on, cashman, eog, showallmap;
  uint8_t show_help, scrollmode, clipping;
  char user_name[MAXPLAYERS][32];
  char ridecule[10][40];
  char savegame[10][22];
  char pwlockout[128], rtsname[128];
  uint8_t overhead_on, last_overhead;

  int16_t pause_on, from_bonus;
  int16_t camerasprite, last_camsprite;
  int16_t last_level, secretlevel;

  int32_t const_visibility, uw_framerate;
  int32_t camera_time, folfvel, folavel, folx, foly, fola;
  int32_t reccnt;

  int32_t entered_name, screen_tilting, shadows, fta_on, executions, auto_run;
  int32_t coords, tickrate, m_coop, coop, screen_size, extended_screen_size, lockout, crosshair, showweapons;
  int32_t mywchoice[MAX_WEAPONS], wchoice[MAXPLAYERS][MAX_WEAPONS], playerai;

  int32_t respawn_monsters, respawn_items, respawn_inventory, recstat, monsters_off, brightness;
  int32_t m_respawn_items, m_respawn_monsters, m_respawn_inventory, m_recstat, m_monsters_off, detail;
  // FIX_00082: /q option taken off when playing a demo (multimode_bot)
  int32_t m_ffire, ffire, m_player_skill, m_level_number, m_volume_number, multimode, multimode_bot;
  int32_t player_skill, level_number, volume_number, m_marker, marker, mouseflip;

  int32_t showcinematics, hideweapon;
  int32_t auto_aim, gitdat_mdk; // AutoAim toggle variable.
  int32_t weaponautoswitch;

  // FIX_00015: Backward compliance with older demos (down to demos v27, 28, 116 and 117 only)
  uint8_t playing_demo_rev;

  uint32_t groupefil_crc32[MAXPLAYERS][4];
  uint16_t conSize[MAXPLAYERS];

#ifdef CHECK_XDUKE_REV
  uint8_t rev[MAXPLAYERS][10];
#endif
  uint32_t mapCRC[MAXPLAYERS];
  uint32_t exeCRC[MAXPLAYERS];
  uint32_t conCRC[MAXPLAYERS];
};
#pragma pack(pop)

struct player_orig
{
  int32_t ox, oy, oz;
  int16_t oa, os;
};

extern uint8_t numplayersprites;

typedef struct
{
  uint32_t crc32;
  char* name;
  uint32_t size;
} crc32_t;

extern crc32_t crc32lookup[];

void add_ammo(short, short, short, short);

extern int32_t fricxv, fricyv;

#pragma pack(push, 4)
struct player_struct
{
  int32_t zoom, exitx, exity, loogiex[64], loogiey[64], numloogs, loogcnt;
  int32_t posx, posy, posz, horiz, ohoriz, ohorizoff, invdisptime;
  int32_t bobposx, bobposy, oposx, oposy, oposz, pyoff, opyoff;
  int32_t posxv, posyv, poszv, last_pissed_time, truefz, truecz;
  int32_t player_par, visibility;
  int32_t bobcounter, weapon_sway;
  int32_t pals_time, randomflamex, crack_time;

  int32_t aim_mode;

  int16_t ang, oang, angvel, cursectnum, look_ang, last_extra, subweapon;
  int16_t ammo_amount[MAX_WEAPONS], wackedbyactor, frag, fraggedself;

  int16_t curr_weapon, last_weapon, tipincs, horizoff, wantweaponfire;
  int16_t holoduke_amount, newowner, hurt_delay, hbomb_hold_delay;
  int16_t jumping_counter, airleft, knee_incs, access_incs;
  int16_t fta, ftq, access_wallnum, access_spritenum;
  int16_t kickback_pic, got_access, weapon_ang, firstaid_amount;
  int16_t somethingonplayer, on_crane, i, one_parallax_sectnum;
  int16_t over_shoulder_on, random_club_frame, fist_incs;
  int16_t one_eighty_count, cheat_phase;
  int16_t dummyplayersprite, extra_extra8, quick_kick;
  int16_t heat_amount, actorsqu, timebeforeexit, customexitsound;

  int16_t weaprecs[16], weapreccnt;
  uint32_t interface_toggle_flag;

  int16_t rotscrnang, dead_flag, show_empty_weapon;
  int16_t scuba_amount, jetpack_amount, steroids_amount, shield_amount;
  int16_t holoduke_on, pycount, weapon_pos, frag_ps;
  int16_t transporter_hold, last_full_weapon, footprintshade, boot_amount;

  int32_t scream_voice;

  uint8_t gm, on_warping_sector, footprintcount;
  uint8_t hbomb_on, jumping_toggle, rapid_fire_hold, on_ground;
  uint8_t name[32], inven_icon, buttonpalette;

  uint8_t jetpack_on, spritebridge, lastrandomspot;
  uint8_t scuba_on, footprintpal, heat_on;

  uint8_t holster_weapon, falling_counter;
  uint8_t gotweapon[MAX_WEAPONS], refresh_inventory;

  // tanguyf: fix the palette pointer size being 32/64-bit dependent. For some reason this is serialised into savegames.
  union
  {
    uint8_t* palette;
    uint64_t _palette_padding;
  };

  uint8_t toggle_key_flag, knuckle_incs; // ,select_dir;
  uint8_t walking_snd_toggle, palookup, hard_landing;
  uint8_t max_secret_rooms, secret_rooms, /*fire_flag,*/ pals[3];
  uint8_t max_actors_killed, actors_killed, return_to_center;

  // local but synch variables (ud is local but not synch):

  // FIX_00023: Moved Addfaz's autoaim handler to synch variables (to avoid out of synch)
  int32_t auto_aim; // AutoAim toggle variable.

  // FIX_00012: added "weapon autoswitch" toggle allowing to turn the autoswitch off
  //            when picking up new weapons. The weapon sound on pickup will remain on, to not
  //           affect the opponent's gameplay (so he can still hear you picking up new weapons)
  int32_t weaponautoswitch;

  uint8_t fakeplayer;
};
#pragma pack(pop)

extern uint8_t tempbuf[2048];
extern uint8_t packbuf[576];

extern int32_t gc, max_player_health, max_armour_amount, max_ammo_amount[MAX_WEAPONS];

extern int32_t impact_damage, respawnactortime, respawnitemtime;

#define MOVFIFOSIZ 256

extern int16_t spriteq[1024], spriteqloc, spriteqamount;
extern struct player_struct ps[MAXPLAYERS];
extern struct player_orig po[MAXPLAYERS];
extern struct user_defs ud;

extern uint16_t global_random;
extern int32_t scaredfallz;
extern char buf[80]; // My own generic input buffer

extern char fta_quotes[NUMOFFIRSTTIMEACTIVE][64];
extern uint8_t scantoasc[128], ready2send;
extern uint8_t scantoascwithshift[128];

extern SAMPLE Sound[NUM_SOUNDS];
extern int32_t VoiceToggle, AmbienceToggle, OpponentSoundToggle;
extern int32_t mouseSensitivity_X, mouseSensitivity_Y;
extern SOUNDOWNER SoundOwner[NUM_SOUNDS][4];

extern uint8_t playerreadyflag[MAXPLAYERS], playerquitflag[MAXPLAYERS];
extern char sounds[NUM_SOUNDS][14];

extern int32_t script[MAXSCRIPTSIZE], *scriptptr, *insptr, *labelcode, labelcnt;
extern char *label, *textptr, error, warning;
extern uint8_t killit_flag;
extern int32_t *actorscrptr[MAXTILES], *parsing_actor;
extern uint8_t actortype[MAXTILES];
extern uint8_t* music_pointer;

extern uint8_t ipath[80], opath[80];

extern char music_fn[4][11][13];
extern uint8_t music_select;
extern char env_music_fn[4][13];
extern int16_t camsprite;

// extern uint8_t  gotz;
extern uint8_t inspace(int16_t sectnum);

#pragma pack(push, 4)
struct weaponhit
{
  uint8_t cgg;
  int16_t picnum, ang, extra, owner, movflag;
  int16_t tempang, actorstayput, dispicnum;
  int16_t timetosleep;
  int32_t floorz, ceilingz, lastvx, lastvy, bposx, bposy, bposz;
  int32_t temp_data[6];
};
#pragma pack(pop)

extern struct weaponhit hittype[MAXSPRITES];

extern input loc;
extern input recsync[RECSYNCBUFSIZ];
extern int32_t avgfvel, avgsvel, avgavel, avghorz, avgbits;

extern int16_t numplayers, myconnectindex;
extern int16_t connecthead, connectpoint2[MAXPLAYERS]; // Player linked list variables (indeces, not connection numbers)
extern int16_t screenpeek;

extern int32_t current_menu;
extern int32_t tempwallptr, animatecnt;
extern int32_t lockclock;
extern uint8_t display_mirror, rtsplaying;

extern int32_t movefifoend[MAXPLAYERS];
extern int32_t ototalclock;

extern int32_t *animateptr[MAXANIMATES], animategoal[MAXANIMATES];
extern int32_t animatevel[MAXANIMATES];
// extern int32_t oanimateval[MAXANIMATES];
extern int16_t neartagsector, neartagwall, neartagsprite;
extern int32_t neartaghitdist;
extern int16_t animatesect[MAXANIMATES];
extern int32_t movefifoplc, vel, svel, angvel, horiz;

extern int16_t mirrorwall[64], mirrorsector[64], mirrorcnt;

#define NUMKEYS 19

extern int32_t chainplace, chainnumpages;
extern volatile int32_t checksume;

#include "funct.h"
// #include "engine_protos.h"

extern uint8_t screencapt;
extern int16_t soundps[NUM_SOUNDS], soundpe[NUM_SOUNDS], soundvo[NUM_SOUNDS];
extern uint8_t soundpr[NUM_SOUNDS], soundm[NUM_SOUNDS];
extern int32_t soundsiz[NUM_SOUNDS];
extern char level_names[44][33];
extern int32_t partime[44], designertime[44];
extern char volume_names[4][33];
extern char skill_names[5][33];
extern char level_file_names[44][128];

extern int32_t SoundToggle, MusicToggle;
extern int16_t last_threehundred, lastsavedpos;
extern uint8_t restorepalette;

extern int16_t buttonstat;
extern int32_t cachecount;
extern uint8_t waterpal[768], slimepal[768], titlepal[768], drealms[768], endingpal[768];
extern char boardfilename[128];
extern uint8_t betaname[80];
extern uint8_t earthquaketime;
extern uint8_t networkmode;
extern uint8_t lumplockbyte[11];

// DUKE3D.H - replace the end "my's" with this
extern int32_t myx, omyx, myxvel, myy, omyy, myyvel, myz, omyz, myzvel;
extern int16_t myhoriz, omyhoriz, myhorizoff, omyhorizoff, globalskillsound;
extern int16_t myang, omyang, mycursectnum, myjumpingcounter;
extern uint8_t myjumpingtoggle, myonground, myhardlanding, myreturntocenter;
extern int32_t fakemovefifoplc;
extern int32_t myxbak[MOVEFIFOSIZ], myybak[MOVEFIFOSIZ], myzbak[MOVEFIFOSIZ];
extern int32_t myhorizbak[MOVEFIFOSIZ];
extern int16_t myangbak[MOVEFIFOSIZ];

extern int16_t weaponsandammosprites[15];

// DUKE3D.H:
typedef struct
{
  int16_t frag[MAXPLAYERS], got_access, last_extra, shield_amount, curr_weapon;
  int16_t ammo_amount[MAX_WEAPONS], holoduke_on;
  uint8_t gotweapon[MAX_WEAPONS], inven_icon, jetpack_on, heat_on;
  int16_t firstaid_amount, steroids_amount, holoduke_amount, jetpack_amount;
  int16_t heat_amount, scuba_amount, boot_amount;
  int16_t last_weapon, weapon_pos, kickback_pic;

} STATUSBARTYPE;

extern STATUSBARTYPE sbar;
extern int16_t frags[MAXPLAYERS][MAXPLAYERS];
extern int32_t cameradist, cameraclock, dukefriction, show_shareware;
extern uint8_t networkmode, movesperpacket;
extern uint8_t gamequit;

extern uint8_t pus, pub, camerashitable, freezerhurtowner, lasermode;
extern uint8_t syncstat, syncval[MAXPLAYERS][MOVEFIFOSIZ];
extern int8_t multiwho, multipos, multiwhat, multiflag;
extern int32_t syncvalhead[MAXPLAYERS], syncvaltail, syncvaltottail;
extern int32_t numfreezebounces, rpgblastradius, pipebombblastradius, tripbombblastradius, shrinkerblastradius, morterblastradius, bouncemineblastradius, seenineblastradius;
// CTW - MODIFICATION
// extern uint8_t  stereo,eightytwofifty,playerswhenstarted,playonten,everyothertime;
extern uint8_t stereo, playerswhenstarted, everyothertime;
// CTW END - MODIFICATION
extern int32_t myminlag[MAXPLAYERS], mymaxlag, otherminlag, bufferjitter;

extern int32_t numinterpolations, startofdynamicinterpolations;
extern int32_t oldipos[MAXINTERPOLATIONS];
extern int32_t bakipos[MAXINTERPOLATIONS];
extern int32_t* curipos[MAXINTERPOLATIONS];

extern int16_t numclouds, clouds[128], cloudx[128], cloudy[128];
extern int32_t cloudtotalclock, totalmemory;

extern int32_t myaimmode, myaimstat, omyaimstat;

extern uint8_t nHostForceDisableAutoaim;

#endif // include-once header.
