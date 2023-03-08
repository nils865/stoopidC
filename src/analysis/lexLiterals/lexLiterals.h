#ifndef LEX_LITERALS_H
#define LEX_LITERALS_H

#include "../wordComponent/wordComponent.h"

Word lexString(char *line, size_t *i);
void lexInt(Word *word);
Word lexFloat();

#endif
