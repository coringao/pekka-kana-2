// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// The public release, rewritten and continued by Carlos Donizete Froes
// is governed by a BSD-2-clause license.
//

/* INCLUDES -----------------------------------------------------------------*/

#include "PisteLanguage.h"
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <cstring>

/*---------------------------------------------------------------------------*/

using namespace std;

const int       LUE_SKIP    = 0,
                LUE_OTSIKKO = 1,
                LUE_TEKSTI  = 2;

const char MARKER_1 = '*',
           MARKER_2 = ':';

PisteLanguage::PisteLanguage(){
	read = LUE_SKIP;
	for (int i=0;i<MAX_TEXTS;i++){
		strcpy(tekstit[i],"");
		strcpy(otsikot[i],"");
	}

}

PisteLanguage::PisteLanguage(char *tiedosto){
	read = LUE_SKIP;

	for (int i=0;i<MAX_TEXTS;i++){
		strcpy(tekstit[i],"");
		strcpy(otsikot[i],"");
	}

	Read_File(tiedosto);
}

PisteLanguage::~PisteLanguage(){}

bool PisteLanguage::Read_File(char *filename){

	ifstream *tiedosto = new ifstream(filename, ios::in);

	if (tiedosto->fail()){
		delete (tiedosto);
		return false;
	}

	for (int i=0;i<MAX_TEXTS;i++){
		strcpy(tekstit[i],"");
		strcpy(otsikot[i],"");
	}

	char merkki;
	int taulukko_index = 0;
	int mjono_index = 0;
	read = LUE_SKIP;

	bool jatka = true;

	while(jatka && tiedosto->peek() != EOF){
		merkki = tiedosto->get();

		switch (merkki){
			case MARKER_1:
				if (read == LUE_SKIP){
					read = LUE_OTSIKKO;
					mjono_index = 0;
				} else{
					read = LUE_SKIP;
					taulukko_index++;
				}
				break;

			case MARKER_2:
				if (read == LUE_OTSIKKO){
					read = LUE_TEKSTI;
					mjono_index = 0;
					break;
				}
				if (read == LUE_TEKSTI){
					if (mjono_index < MAX_TEXT_LENGTH){
						tekstit[taulukko_index][mjono_index] = merkki;
						tekstit[taulukko_index][mjono_index+1] = '\0';
						mjono_index++;
					}
				}
				break;

			case '\r':
			case '\n':
				if (read != LUE_SKIP){
					read = LUE_SKIP;
					taulukko_index++;
				}
				break;

			case '\t': break;
			case '\v': break;

			default:
				if (read != LUE_SKIP && !(mjono_index == 0 && merkki == ' ')){
					if (read == LUE_OTSIKKO){
						if (mjono_index < MAX_HEAD_LENGTH){
							otsikot[taulukko_index][mjono_index] = merkki;
							otsikot[taulukko_index][mjono_index+1] = '\0';
							mjono_index++;
						}
					}
					if (read == LUE_TEKSTI){
						if (mjono_index < MAX_TEXT_LENGTH){
							tekstit[taulukko_index][mjono_index] = merkki;
							tekstit[taulukko_index][mjono_index+1] = '\0';
							mjono_index++;
						}
					}
				}
				break;
		}

		if (taulukko_index >= MAX_TEXTS)
			jatka = false;
	}

	delete tiedosto;

	return true;
}

int PisteLanguage::Hae_Indeksi(char *otsikko){
	int i=0;

	while (i < MAX_TEXTS && strcmp(otsikot[i],otsikko) != 0)
		i++;

	if (i == MAX_TEXTS)
		return -1;

	return i;

}

char* PisteLanguage::Hae_Teksti(int index){
	if (index >= 0 && index < MAX_TEXTS)
		return tekstit[index];
	else
		return ".....";
}

void PisteLanguage::Korvaa_Teksti(int index, char *teksti){
	if (index >= 0 && index < MAX_TEXTS)
		strcpy(tekstit[index],teksti);
}
