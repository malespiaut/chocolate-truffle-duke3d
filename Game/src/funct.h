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

#ifndef FUNCT_H
#define FUNCT_H

#include "duke3d.h"

extern void sendscore(char* s);
extern void SoundStartup(void);
extern void SoundShutdown(void);
extern void MusicStartup(void);
extern void MusicShutdown(void);
extern int32_t USRHOOKS_GetMem(void** ptr, uint32_t size);
extern int32_t USRHOOKS_FreeMem(void* ptr);
extern void intomenusounds(void);
extern void playmusic(char* fn);
extern uint8_t loadsound(uint16_t num);
extern int32_t xyzsound(int16_t num, int16_t i, int32_t x, int32_t y, int32_t z);
extern void sound(int16_t num);
extern int32_t spritesound(uint16_t num, int16_t i);
extern void stopsound(int16_t num);
extern void stopenvsound(int16_t num, int16_t i);
extern void pan3dsound(void);
extern void TestCallBack(int32_t num);
extern int16_t callsound(int16_t sn, int16_t whatsprite);
extern int16_t check_activator_motion(int16_t lotag);
extern uint8_t isadoorwall(int16_t dapic);
extern uint8_t isanunderoperator(int16_t lotag);
extern uint8_t isanearoperator(int16_t lotag);
extern int16_t checkcursectnums(int16_t sect);
extern int32_t ldist(spritetype* s1, spritetype* s2);
extern int32_t dist(spritetype* s1, spritetype* s2);
extern int16_t findplayer(spritetype* s, int32_t* d);
extern int16_t findotherplayer(int16_t p, int32_t* d);
extern void doanimations(void);
extern int32_t getanimationgoal(int32_t* animptr);
extern int32_t setanimation(int16_t animsect, int32_t* animptr, int32_t thegoal, int32_t thevel);
extern void animatecamsprite(void);
extern void animatewalls(void);
extern uint8_t activatewarpelevators(int16_t s, int16_t d);
extern void operatesectors(int16_t sn, int16_t ii);
extern void operaterespawns(int16_t low);
extern void operateactivators(int16_t low, int16_t snum);
extern void operatemasterswitches(int16_t low);
extern void operateforcefields(int16_t s, int16_t low);
extern uint8_t checkhitswitch(int16_t snum, int32_t w, uint8_t switchtype);
extern void activatebysector(int16_t sect, int16_t j);
extern void checkhitwall(int16_t spr, int16_t dawallnum, int32_t x, int32_t y, int32_t z, int16_t atwith);
extern void checkplayerhurt(struct player_struct* p, int16_t j);
extern uint8_t checkhitceiling(int16_t sn);
extern void checkhitsprite(int16_t i, int16_t sn);
extern void allignwarpelevators(void);
extern void cheatkeys(int16_t snum);
extern void checksectors(int16_t snum);
extern void RTS_AddFile(char* filename);
extern void RTS_Init(char* filename);
extern int32_t RTS_NumSounds(void);
extern int32_t RTS_SoundLength(int32_t lump);
extern char* RTS_GetSoundName(int32_t i);
extern void RTS_ReadLump(int32_t lump, void* dest);
extern void* RTS_GetSound(int32_t lump);
extern void xyzmirror(int16_t i, int16_t wn);
extern void vscrn(void);
int32_t countfragbars(void);
extern void pickrandomspot(int16_t snum);
extern void resetplayerstats(int16_t snum);
extern void resetweapons(int16_t snum);
extern void resetinventory(int16_t snum);
extern void resetprestat(int16_t snum, uint8_t g);
extern void setupbackdrop(int16_t backpicnum);
extern void cachespritenum(int16_t i);
extern void cachegoodsprites(void);
extern void prelevel(uint8_t g);
extern void newgame(uint8_t vn, uint8_t ln, uint8_t sk);
extern void resetpspritevars(uint8_t g);
extern void resettimevars(void);
extern void genspriteremaps(void);
extern void waitforeverybody(void);
extern uint8_t checksum(int32_t sum);
extern uint8_t getsound(uint16_t num);
extern void precachenecessarysounds(void);
extern void cacheit(void);
extern void dofrontscreens(void);
extern void enterlevel(uint8_t g);
extern void setpal(struct player_struct* p);
extern void incur_damage(struct player_struct* p);
extern void quickkill(struct player_struct* p);
extern void forceplayerangle(struct player_struct* p);
extern void tracers(int32_t x1, int32_t y1, int32_t z1, int32_t x2, int32_t y2, int32_t z2, int32_t n);
extern int32_t hits(int16_t i);
extern int32_t hitasprite(int16_t i, short* hitsp);
extern int32_t hitawall(struct player_struct* p, short* hitw);
extern int16_t aim(spritetype* s, int16_t aang, int16_t auto_aim);
extern void shoot(int16_t i, int16_t atwith);
extern void displayloogie(int16_t snum);
extern uint8_t animatefist(int16_t gs, int16_t snum);
extern uint8_t animateknee(int16_t gs, int16_t snum);
extern uint8_t animateknuckles(int16_t gs, int16_t snum);
extern void displaymasks(int16_t snum);
extern uint8_t animatetip(int16_t gs, int16_t snum);
extern uint8_t animateaccess(int16_t gs, int16_t snum);
extern void displayweapon(int16_t snum);
extern void getinput(int16_t snum);
extern uint8_t doincrements(struct player_struct* p);
extern void checkweapons(struct player_struct* p);
extern void processinput(int16_t snum);
extern void cmenu(int16_t cm);
extern void savetemp(char* fn, uint8_t* daptr, int32_t dasiz);
extern void getangplayers(int16_t snum);
extern int32_t loadpheader(uint8_t spot, int32_t* vn, int32_t* ln, int32_t* psk, int32_t* numplr);
extern int32_t loadplayer(int8_t spot);
extern int32_t saveplayer(int8_t spot);
extern void sendgameinfo(void);
extern int32_t probe(int32_t x, int32_t y, int32_t i, int32_t n);
extern int32_t probeXduke(int32_t x, int32_t y, int32_t i, int32_t n, int32_t spriteSize);
extern int32_t menutext(int32_t x, int32_t y, int16_t s, int16_t p, char* t);
extern int32_t menutextc(int32_t x, int32_t y, int16_t s, int16_t p, char* t);
extern void bar(int32_t x, int32_t y, short* p, int16_t dainc, uint8_t damodify, int16_t s, int16_t pa);
extern void dispnames(void);
extern int32_t getfilenames(char kind[]);
extern void sortfilenames(void);
extern void menus(void);
void gameexitanycase(void);
extern void palto(uint8_t r, uint8_t g, uint8_t b, int32_t e, int32_t present);
extern void drawoverheadmap(int32_t cposx, int32_t cposy, int32_t czoom, int16_t cang);
extern void playanm(char* fn, uint8_t);
extern int16_t getincangle(int16_t a, int16_t na);
extern uint8_t ispecial(uint8_t c);
extern uint8_t isaltok(uint8_t c);
extern void getglobalz(int16_t i);
extern void makeitfall(int16_t i);
extern void getlabel(void);
extern int32_t keyword(void);
extern int32_t transword(void);
extern void transnum(void);
extern uint8_t parsecommand(int32_t readfromGRP);
extern void passone(int32_t readfromGRP);
extern void loadefs(char* fn, char* mptr, int32_t readfromGRP);
extern uint8_t dodge(spritetype* s);
extern int16_t furthestangle(int16_t i, int16_t angs);
extern int16_t furthestcanseepoint(int16_t i, spritetype* ts, int32_t* dax, int32_t* day);
extern void alterang(int16_t a);
extern void move(void);
extern void parseifelse(int32_t condition);
extern uint8_t parse(void);
extern void execute(int16_t i, int16_t p, int32_t x);
extern void overwritesprite(int32_t thex, int32_t they, int16_t tilenum, int8_t shade, uint8_t stat, uint8_t dapalnum);
extern void timerhandler(void);
extern int32_t inittimer(int);
extern void uninittimer(void);
extern int32_t gametext(int32_t x, int32_t y, char* t, uint8_t s, int16_t dabits);
extern int32_t gametextpart(int32_t x, int32_t y, char* t, uint8_t s, int16_t p);
extern int32_t minitext(int32_t x, int32_t y, char* t, uint8_t p, uint8_t sb);
extern void gamenumber(int32_t x, int32_t y, int32_t n, uint8_t s);
extern void ShutDown(void);
extern void allowtimetocorrecterrorswhenquitting(void);
extern void getpackets(void);
extern void faketimerhandler(void);
extern void checksync(void);
extern void check_fta_sounds(int16_t i);
extern int16_t inventory(spritetype* s);
extern int16_t badguy(spritetype* s);
extern int16_t badguypic(int16_t pn);
extern void myos(int32_t x, int32_t y, int16_t tilenum, int8_t shade, uint8_t orientation);
extern void myospal(int32_t x, int32_t y, int16_t tilenum, int8_t shade, uint8_t orientation, uint8_t p);
extern void invennum(int32_t x, int32_t y, uint8_t num1, uint8_t ha, uint8_t sbits);
extern void weaponnum(int16_t ind, int32_t x, int32_t y, int32_t num1, int32_t num2, uint8_t ha);
extern void weaponnum999(uint8_t ind, int32_t x, int32_t y, int32_t num1, int32_t num2, uint8_t ha);
extern void weapon_amounts(struct player_struct* p, int32_t x, int32_t y, int32_t u);
extern void digitalnumber(int32_t x, int32_t y, int32_t n, uint8_t s, uint8_t cs);
extern void scratchmarks(int32_t x, int32_t y, int32_t n, uint8_t s, uint8_t p);
extern void displayinventory(struct player_struct* p);
extern void displayfragbar(void);
void drawsmallweapon(int16_t weapon, float scale, int16_t x, int16_t y); // xduke
extern void coolgaugetext(int16_t snum);
extern void tics(int16_t offx, int16_t offy, int16_t color);
extern void clocks(void);
extern void coords(int16_t snum);
extern void operatefta(void);
extern void FTA(int16_t q, struct player_struct* p, int32_t mode);
extern void showtwoscreens(void);

extern void gameexit(char* t);
extern int16_t strget(int16_t x, int16_t y, char* t, int16_t dalen, int16_t c);
extern void displayrest(int32_t smoothratio);
extern void updatesectorz(int32_t x, int32_t y, int32_t z, short* sectnum);
extern void view(struct player_struct* pp, int32_t* vx, int32_t* vy, int32_t* vz, short* vsectnum, int16_t ang, int16_t horiz);
extern void drawbackground(void);
extern void displayrooms(int16_t snum, int32_t smoothratio);
extern int16_t LocateTheLocator(int16_t n, int16_t sn);
extern int16_t EGS(int16_t whatsect, int32_t s_x, int32_t s_y, int32_t s_z, int16_t s_pn, int8_t s_s, int8_t s_xr, int8_t s_yr, int16_t s_a, int16_t s_ve, int32_t s_zv, int16_t s_ow, int8_t s_ss);
extern uint8_t wallswitchcheck(int16_t i);
extern int16_t spawn(int16_t j, int16_t pn);
extern void animatesprites(int32_t x, int32_t y, int16_t a, int32_t smoothratio);
extern void cheats(void);
extern void nonsharedkeys(void);
extern void comlinehelp(char** argv);
extern void checkcommandline(int32_t argc, char** argv);
extern void printstr(int16_t x, int16_t y, uint8_t string[], uint8_t attribute);
extern void Logo(void);
extern void loadtmb(void);
extern void compilecons(void);
extern int32_t encodescriptptr(int32_t* scptr);
extern int32_t* decodescriptptr(int32_t scptr);
extern void Startup(void);
extern void getnames(void);
extern int main(const int argc, const char** argv);
extern uint8_t opendemoread(uint8_t which_demo);
extern void opendemowrite(void);
extern void record(void);
extern void closedemowrite(void);
extern int32_t playback(void);
extern uint8_t moveloop(void);
extern void fakedomovethingscorrect(void);
extern void fakedomovethings(void);
extern uint8_t domovethings(void);
extern void displaybonuspics(int16_t x, int16_t y, int16_t p);
extern void doorders(void);
extern void dobonus(uint8_t bonusonly);
extern void cameratext(int16_t i);
extern void vglass(int32_t x, int32_t y, int16_t a, int16_t wn, int16_t n);
extern void lotsofglass(int16_t i, int16_t wallnum, int16_t n);
extern void spriteglass(int16_t i, int16_t n);
extern void ceilingglass(int16_t i, int16_t sectnum, int16_t n);
extern void lotsofcolourglass(int16_t i, int16_t wallnum, int16_t n);
extern void SetupGameButtons(void);
extern int32_t GetTime(void);
extern void CenterCenter(void);
extern void UpperLeft(void);
extern void LowerRight(void);
extern void CenterThrottle(void);
extern void CenterRudder(void);
extern void takescreenshot(void);
extern void CONFIG_GetSetupFilename(void);
extern int32_t CONFIG_FunctionNameToNum(char* func);
extern char* CONFIG_FunctionNumToName(int32_t func);
extern int32_t CONFIG_AnalogNameToNum(char* func);
extern void CONFIG_SetDefaults(void);
extern void CONFIG_ReadKeys(void);
extern void CONFIG_SetupMouse(int32_t scripthandle);
extern void CONFIG_SetupGamePad(int32_t scripthandle);
extern void CONFIG_SetupJoystick(int32_t scripthandle);
extern void readsavenames(void);
extern void CONFIG_ReadSetup(void);
extern void CONFIG_WriteSetup(void);
extern void CheckAnimStarted(uint8_t* funcname);
extern uint16_t findpage(uint16_t framenumber);
extern void loadpage(uint16_t pagenumber, uint16_t* pagepointer);
extern void CPlayRunSkipDump(uint8_t* srcP, uint8_t* dstP);
extern void renderframe(uint16_t framenumber, uint16_t* pagepointer);
extern void drawframe(uint16_t framenumber);
extern void ANIM_LoadAnim(uint8_t* buffer);
extern void ANIM_FreeAnim(void);
extern int32_t ANIM_NumFrames(void);
extern uint8_t* ANIM_DrawFrame(int32_t framenumber);
extern uint8_t* ANIM_GetPalette(void);
extern void updateinterpolations(void);
extern void setinterpolation(int32_t* posptr);
extern void stopinterpolation(int32_t* posptr);
extern void dointerpolations(int32_t smoothratio);
extern void restoreinterpolations(void);
extern int32_t ceilingspace(int16_t sectnum);
extern int32_t floorspace(int16_t sectnum);
extern void addammo(int16_t weapon, struct player_struct* p, int16_t amount);
extern void addweapon(struct player_struct* p, int16_t weapon);
extern void checkavailinven(struct player_struct* p);
extern void checkavailweapon(struct player_struct* p);
extern int32_t ifsquished(int16_t i, int16_t p);
extern void hitradius(int16_t i, int32_t r, int32_t hp1, int32_t hp2, int32_t hp3, int32_t hp4);
extern int32_t movesprite(int16_t spritenum, int32_t xchange, int32_t ychange, int32_t zchange, uint32_t cliptype);
extern int16_t ssp(int16_t i, uint32_t cliptype);
extern void insertspriteq(int16_t i);
extern void lotsofmoney(spritetype* s, int16_t n);
extern void guts(spritetype* s, int16_t gtype, int16_t n, int16_t p);
extern void setsectinterpolate(int16_t i);
extern void clearsectinterpolate(int16_t i);
extern void ms(int16_t i);
extern void movefta(void);
extern int16_t ifhitsectors(int16_t sectnum);
extern int16_t ifhitbyweapon(int16_t sn);
extern void movecyclers(void);
extern void movedummyplayers(void);
extern void moveplayers(void);
extern void movefx(void);
extern void movefallers(void);
extern void movestandables(void);
extern void bounce(int16_t i);
extern void moveweapons(void);
extern void movetransports(void);
extern void moveeffectors(void);
extern void moveactors(void);
extern void moveexplosions(void);

#endif
