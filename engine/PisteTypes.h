// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// The public release, rewritten and continued by Carlos Donizete Froes
// is governed by a BSD-2-clause license.
//

/* INCLUDES -----------------------------------------------------------------*/

#include <stdint.h>

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef P_TYPES
#define P_TYPES

typedef uint8_t  BYTE;
typedef uint16_t WORD;
#ifdef _WIN32
typedef unsigned long DWORD;
#else
typedef uint32_t DWORD;
#endif

#endif
