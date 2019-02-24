// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// The public release, rewritten and continued by Carlos Donizete Froes
// is governed by a BSD-2-clause license.
//

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef P_ENGINE
#define P_ENGINE

/* INCLUDES -----------------------------------------------------------------*/

#include "PisteDraw.h"
#include "PisteInput.h"
#include "PisteSound.h"
#include "PisteUtils.h"
#include "PisteLanguage.h"
#include "PistePlatform.h"
#include "PisteTypes.h"

/*---------------------------------------------------------------------------*/

void Piste_IgnoreFrame();
void Piste_SetFPS(int fps);
int  Piste_GetFPS();
void Piste_SetDebug(bool set);

int Piste_Init(int width, int height, const char* name);
int Piste_Loop(bool &running, int (*GameLogic)());
int Piste_Quit();

#endif
