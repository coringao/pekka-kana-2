// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// This public release and rewritten is governed by a BSD-2-clause license.
//

/* INCLUDES -----------------------------------------------------------------*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "log.h"

/* VARIABLES ----------------------------------------------------------------*/

bool	kirjoita_pisteloki = false;

/* METHODS ------------------------------------------------------------------*/

void PisteLog_Salli_Kirjoitus() {
		kirjoita_pisteloki = true;	
}

int PisteLog_Kirjoita(char *viesti) {

	if (kirjoita_pisteloki) {
	
		int virhe = 0;

		char *filename = "log.txt";
			
		FILE *tiedosto;

		if ((tiedosto = fopen(filename, "a")) == NULL)
		{
			return(1);
		}

		char mjono[255];

		strcpy(mjono,viesti);

		fwrite(mjono,	sizeof(char),	strlen(mjono),  tiedosto);

		fclose(tiedosto);
	}

	return(0);
}
