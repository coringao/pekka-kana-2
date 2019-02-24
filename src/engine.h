// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// This public release and rewritten is governed by a BSD-2-clause license.
//

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef P_ENGINE
#define P_ENGINE

/* INCLUDES -----------------------------------------------------------------*/

#include "draw.h"
#include "input.h"
#include "sound.h"
#include "utils.h"
#include "language.h"
#include "platform.h"
#include "types.h"

/*---------------------------------------------------------------------------*/

void Piste_IgnoreFrame();
void Piste_SetFPS(int fps);
int  Piste_GetFPS();
void Piste_SetDebug(bool set);

int Piste_Init(int width, int height, const char* name);
int Piste_Loop(bool &running, int (*GameLogic)());
int Piste_Quit();

#endif
