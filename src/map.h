// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// The public release, rewritten and continued by Carlos Donizete Froes
// is governed by a BSD-2-clause license.
//

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef PK2MAP
#define PK2MAP

/* INCLUDES -----------------------------------------------------------------*/

#include "PistePlatform.h"
#include "PisteTypes.h"
#include <string.h>

/*---------------------------------------------------------------------------*/

typedef struct {
	int left, top, right, bottom;
} RECT;

const char PK2KARTTA_VIIMEISIN_VERSIO[4]                = "1.3";

const DWORD PK2KARTTA_KARTTA_LEVEYS                     = 256;
const DWORD PK2KARTTA_KARTTA_KORKEUS                    = 224;
const DWORD PK2KARTTA_KARTTA_KOKO	                = PK2KARTTA_KARTTA_LEVEYS * PK2KARTTA_KARTTA_KORKEUS;
const DWORD PK2KARTTA_BLOCK_PALETTI_LEVEYS              = 320;
const DWORD PK2KARTTA_BLOCK_PALETTI_KORKEUS             = 480;
const BYTE PK2KARTTA_TAUSTAKUVA_EI	                = 0;
const BYTE PK2KARTTA_EXTRA_EI		                = 0;

const DWORD PK2KARTTA_KARTTA_MAX_PROTOTYYPPEJA          = 100;

const BYTE BLOCK_ESTO_ALAS		                = 40;
const BYTE BLOCK_HISSI_HORI		                = 41;
const BYTE BLOCK_HISSI_VERT		                = 42;
const BYTE BLOCK_KYTKIN2_YLOS	                        = 43;
const BYTE BLOCK_KYTKIN2_ALAS	                        = 45;
const BYTE BLOCK_KYTKIN3_OIKEALLE                       = 44;
const BYTE BLOCK_KYTKIN3_VASEMMALLE                     = 46;
const BYTE BLOCK_LUKKO			                = 47;
const BYTE BLOCK_KALLOSEINA		                = 48;
const BYTE BLOCK_KALLOTAUSTA		                = 49;
const BYTE BLOCK_ANIM1			                = 60;
const BYTE BLOCK_ANIM2			                = 65;
const BYTE BLOCK_ANIM3			                = 70;
const BYTE BLOCK_ANIM4			                = 75;
const BYTE BLOCK_VIRTA_VASEMMALLE                       = 140;
const BYTE BLOCK_VIRTA_OIKEALLE	                        = 141;
const BYTE BLOCK_VIRTA_YLOS		                = 142;
const BYTE BLOCK_PIILO			                = 143;
const BYTE BLOCK_TULI			                = 144;
const BYTE BLOCK_KYTKIN1			        = 145;
const BYTE BLOCK_KYTKIN2			        = 146;
const BYTE BLOCK_KYTKIN3			        = 147;
const BYTE BLOCK_ALOITUS			        = 148;
const BYTE BLOCK_LOPETUS			        = 149;

const int KYTKIN_ALOITUSARVO		                = 2000;

const BYTE ILMA_NORMAALI			        = 0;
const BYTE ILMA_SADE				        = 1;
const BYTE ILMA_METSA				        = 2;
const BYTE ILMA_SADEMETSA			        = 3;
const BYTE ILMA_LUMISADE			        = 4;

const BYTE TAUSTA_STAATTINEN			        = 0;
const BYTE TAUSTA_PALLARX_VERT			        = 1;
const BYTE TAUSTA_PALLARX_HORI			        = 2;
const BYTE TAUSTA_PALLARX_VERT_JA_HORI	                = 3;

void PK2Kartta_Cos_Sin(double *cost, double *sint);
void PK2Kartta_Animoi(int degree, int anim, int aika1, int aika2, int aika3, bool keys);
void PK2Kartta_Aseta_Ruudun_Mitat(int leveys, int korkeus);

class PK2Kartta
{
	public:

	/* Atributs ------------------------*/

	char		versio[5];
	char		palikka_bmp[13];
	char		taustakuva[13];
	char		musiikki[13];

	char		nimi[40];
	char		tekija[40];

	int		jakso;
	int		ilma;
	int		aika;
	BYTE		extra;
	BYTE		tausta;
	DWORD		kytkin1_aika;
	DWORD		kytkin2_aika;
	DWORD		kytkin3_aika;
	int		pelaaja_sprite;

	BYTE		taustat[PK2KARTTA_KARTTA_KOKO];
	BYTE		seinat [PK2KARTTA_KARTTA_KOKO];
	BYTE		spritet[PK2KARTTA_KARTTA_KOKO];
	char		protot [PK2KARTTA_KARTTA_MAX_PROTOTYYPPEJA][13];
	bool		reunat [PK2KARTTA_KARTTA_KOKO];

	int		palikat_buffer;
	int		taustakuva_buffer;
	int		palikat_vesi_buffer;

	int	        x,y;
	int	        ikoni;

	static char	pk2_hakemisto[256];

	/* Metodit --------------------------*/

	PK2Kartta();
	PK2Kartta(const PK2Kartta &kartta);
	~PK2Kartta();

	PK2Kartta &operator = (const PK2Kartta &kartta);

	int Lataa(char *polku, char *nimi);		// Lataa kartta
	int Lataa_Pelkat_Tiedot(char *polku, char *nimi);	// Lataa kartta ilman grafiikoita
	int LataaVersio01(char *filename);	// Lataa kartta versio 0.1
	int LataaVersio10(char *filename);	// Lataa kartta versio 1.0
	int LataaVersio11(char *filename);	// Lataa kartta versio 1.1
	int LataaVersio12(char *filename);      // Lataa kartta versio 1.2
	int LataaVersio13(char *filename);      // Lataa kartta versio 1.3
	int Tallenna(char *filename);	        // Save map
	void Tyhjenna();			// Tyhjenna kartta
	RECT LaskeTallennusAlue(BYTE *lahde, BYTE *&kohde);
	RECT LaskeTallennusAlue(BYTE *alue);
	void LueTallennusAlue(BYTE *lahde, RECT alue, int kohde);
	int Lataa_Taustakuva(char *polku, char *filename);
	int Lataa_PalikkaPaletti(char *polku, char *filename);
	int Lataa_TaustaMusiikki(char *filename);
	int Piirra_Taustat(int, int, bool);
	int Piirra_Seinat (int, int, bool);
	void Kopioi(PK2Kartta &kartta);
	void Animoi_Tuli(void);
	void Animoi_Vesiputous(void);
	void Animoi_Virta_Ylos(void);
	void Animoi_Vedenpinta(void);
	void Animoi_Vesi(void);
};

#endif
