// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// This public release and rewritten is governed by a BSD-2-clause license.
//

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef PISTELANGUAGE
#define PISTELANGUAGE

/*---------------------------------------------------------------------------*/

const int MAX_TEXTS = 200;
const int MAX_TEXT_LENGTH = 80;
const int MAX_HEAD_LENGTH = 50;

class PisteLanguage{
	public:
		PisteLanguage();
		PisteLanguage(char *filename);
		~PisteLanguage();
		bool Read_File(char *filename);
		int Hae_Indeksi(char *title);
		char* Hae_Teksti(int index);
		void Korvaa_Teksti(int index, char *teksti);

	private:
		char tekstit[MAX_TEXTS][MAX_TEXT_LENGTH+1];
		char otsikot[MAX_TEXTS][MAX_HEAD_LENGTH+1];
		int  read;
};

#endif
