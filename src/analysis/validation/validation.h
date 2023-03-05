#ifndef VALIDATION_H
#define VALIDATION_H

#include "../wordComponent/wordComponent.h"

char *getWordType(char *value);

Word validateComment(Word commentPrefix, char *comment);

#endif
