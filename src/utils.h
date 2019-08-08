// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// This file is part of Pekka Kana 2, the original license of the author can be
// found in the file 'license.txt'.
//

/* INCLUDES -----------------------------------------------------------------*/

#include "platform.h"

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef PISTEUTILS
#define PISTEUTILS

/*---------------------------------------------------------------------------*/

void    PisteUtils_Lower(char* string);
void    PisteUtils_RemoveSpace(char* string);
char    *PisteUtils_FindImage(char *filename);
int     PisteUtils_CreateDir(const char *directory);
int     PisteUtils_Scandir(const char* type, char* dir, char (*list)[_MAX_PATH], int length);
#endif
