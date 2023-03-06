#ifndef LEX_LITERALS_H
#define LEX_LITERALS_H

#include "../sentenceComponent/sentenceComponent.h"
#include "../wordComponent/wordComponent.h"

Word lexString(char *line, size_t *i);

Sentence lexLiterals(Sentence statement);

#endif
