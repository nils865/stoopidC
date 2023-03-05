#ifndef SENTENCE_COMPONENT_H
#define SENTENCE_COMPONENT_H

#include <stdlib.h>

#include "../wordComponent/wordComponent.h"

typedef struct
{
    Word *words;
    size_t length;
} Sentence;

Sentence wordsToSentence(Word *words);

void outputSentence(Sentence sentence);

#endif
