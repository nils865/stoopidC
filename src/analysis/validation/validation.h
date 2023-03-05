#ifndef VALIDATION_H
#define VALIDATION_H

#include "../wordComponent/wordComponent.h"

extern char *keywords[];
extern char *operators[];
extern char *punctuations[];
extern char *comments[];
extern char *wordTypes[];

char *getWordType(char *value);

Word validateComment(Word commentPrefix, char *comment);

#endif
