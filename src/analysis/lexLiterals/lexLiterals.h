#ifndef LEX_LITERALS_H
#define LEX_LITERALS_H

#include <stdlib.h>

#include "../wordComponent/wordComponent.h"

Word lexString(char *line, size_t *i);

void lexInt(Word *word);

Word lexFloat(Word *previousWord, Word *currentWord, char *line, size_t *i);

#endif
