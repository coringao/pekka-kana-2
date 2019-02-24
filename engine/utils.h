// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// The public release, rewritten and continued by Carlos Donizete Froes
// is governed by a BSD-2-clause license.
//

/* INCLUDES -----------------------------------------------------------------*/

#include "PistePlatform.h"

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef PISTEUTILS
#define PISTEUTILS

/*---------------------------------------------------------------------------*/

void    PisteUtils_Lower(char* string);
void    PisteUtils_RemoveSpace(char* string);
char    *PisteUtils_FindImage(char *filename);
int     PisteUtils_CreateDir(char *directory);
int     PisteUtils_Scandir(const char* type, char* dir, char (*list)[_MAX_PATH], int length);
#endif
