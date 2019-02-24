// Pekka Kana 2 by Janne Kivilahti from Piste Gamez (2003-2007)
// https://pistegamez.net/game_pk2.html
//
// This public release and rewritten is governed by a BSD-2-clause license.
//

/* INCLUDES -----------------------------------------------------------------*/

#include "utils.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/stat.h>
#include <ctype.h>

#ifdef _WIN32
#include <io.h>
#include "winlite.h"
#else
#include <dirent.h>
#endif

void PisteUtils_Lower(char* string){
	int i;
	for(i=0; string[i]!='\0'; i++)
		tolower(string[i]);
}

void PisteUtils_RemoveSpace(char* string){
	int len = strlen(string);
	while(string[len-2]==' '){
		string[len-2]='\0';
		len--;
	}
}

char *PisteUtils_FindImage(char *filename){
	struct stat st;
  char *ret = strdup(filename);

  // expecting it to be 6+3 dos filename
  char *ext = strrchr(ret, '.');
  if(ext == NULL) return NULL;

  // cut up the path and file base components
  char *base = strrchr(ret, '/');
  // just a filename without dir
  if(base == NULL) base = ret;

	strcpy(ext, ".png");
  if(stat(ret, &st) == 0)
    return ret;
  else{
		char *c = base;
  	while(c != ext) *c++ = toupper(*c);

    if(stat(ret, &st) == 0)
      return ret;
    else{
			strcpy(ext, ".bmp");
      if(stat(ret, &st) == 0)
        return ret;
    }
  }
  return NULL;
}

//This need to receive just the filename, not the path
void getext(char* string){
	int i, b = -1, len;
	for(i=0; string[i]!='\0'; i++)
		if(string[i]=='.') b = i;

	if (b == -1) len = -1;
	else len = i - b;

	for(i=0; i<len; i++)
		string[i] = string[b+i];
	string[i] = '\0';
}

#ifdef _WIN32

int PisteUtils_Scandir(const char* type, char* dir, char (*list)[_MAX_PATH], int length){
    struct _finddata_t map_file;
    long hFile;

	int i = 0;
	char buffer[260];
	if (type[0] != '/')
		_snprintf(buffer, sizeof(buffer), "%s/*%s", dir, type);
	else
		_snprintf(buffer, sizeof(buffer), "%s/*", dir, type);

	if((hFile = _findfirst(buffer, &map_file )) == -1L )
       return 1;
	else
	{
		strcpy(list[i], map_file.name);
		i++;
	}

	while (i<length && _findnext( hFile, &map_file ) == 0)
	{
		strcpy(list[i], map_file.name);
		i++;
	}

	_findclose( hFile );

	return i;
}
int PisteUtils_CreateDir(char *directory){
	CreateDirectory(directory, NULL);
	return 0;
}

#else

int PisteUtils_Scandir(const char* type, char* dir, char (*list)[_MAX_PATH], int length){
	int i, numb = 0, files = 0;
	char ext[128];

	struct dirent **namelist;

	numb = scandir(dir, &namelist, 0, alphasort);

	for(i=0; i<numb; i++){
		strcpy(ext,namelist[i]->d_name);
		getext(ext);
		if(type[0] == '/' && namelist[i]->d_type == DT_DIR && i < length){
			strcpy(list[files], namelist[i]->d_name);
			files++;
		}
		else if(strcmp(ext, type) == 0 && i < length){
			strcpy(list[files], namelist[i]->d_name);
			files++;
		}
		delete namelist[i];
	}
	delete namelist;

	return files;
}
int PisteUtils_CreateDir(char *directory){
	char shell[_MAX_PATH];
	strcpy(shell,"mkdir -p ");
	strcat(shell,directory);
	system(shell);
	return 0;
}

#endif
