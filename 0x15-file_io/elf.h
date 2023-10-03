#ifndef _ELF_H_
#define _ELF_H_
#include "main.h"
#include <elf.h>

#define MAGS 64


/*=========  Task #4 (advanced) =========*/
int isElf(char * magic);
void prntHeader(char * magic);
void prntMagic(char *magic);
void prntClass(char *magic);
void prntData(char *magic);
void prntVersion(char *magic);
void prntOS_ABI(char *magic);
void prntABI_Vers(char *magic);
void prntType(char *magic);
void prntEntryPoint(char *magic);
/*========================================*/

#endif
