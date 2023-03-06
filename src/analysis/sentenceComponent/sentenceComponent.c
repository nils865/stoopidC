#include <stdio.h>

#include "sentenceComponent.h"
#include "../../utils/color/color.h"

Sentence wordsToSentence(Word *words)
{
    Sentence sentence;
    sentence.words = words;

    for ((sentence.length = 0); (words[sentence.length].value != NULL); (sentence.length++));

    return sentence;
}

void outputSentence(Sentence sentence)
{
    printf("Sentence length: %lld\n", sentence.length);

    for (int i = 0; i < sentence.length; i++)
    {
        printf(COLOR_CYAN "%s " COLOR_RED "(" COLOR_MAGENTA "%s" COLOR_RED ")" COLOR_RESET " | ", sentence.words[i].value, sentence.words[i].type);
    }

    printf("\n");
}
