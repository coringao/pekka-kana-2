// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// This file is part of Pekka Kana 2, the original license of the author can be
// found in the file 'license.txt'.
//

/* DEFINITIONS --------------------------------------------------------------*/

#ifndef P_SOUND
#define P_SOUND

/*---------------------------------------------------------------------------*/

int PisteSound_Start();
int PisteSound_Update();
int PisteSound_End();

int PisteSound_LoadSFX(char* filename);
void PisteSound_PlaySFX(int index);
void PisteSound_PlaySFX(int index, int volume, int panoramic, int freq);
void PisteSound_SetSFXVolume(int volume);
int PisteSound_FreeSFX(int index);
void PisteSound_ResetSFX();

int PisteSound_StartMusic(char* filename);
void PisteSound_SetMusicVolume(int volume);
void PisteSound_StopMusic();

#endif
