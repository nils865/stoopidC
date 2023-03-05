#include <stdio.h>

#include "sentenceComponent.h"

Sentence wordsToSentence(Word *words)
{
    Sentence sentence;
    sentence.words = words;

    printf("%s\n", sentence.words[0].value);

    for ((sentence.length = 0); (words[sentence.length].value != NULL); (sentence.length++));

    return sentence;
}

void outputSentence(Sentence sentence)
{
    printf("Sentence length: %lld\n", sentence.length);

    for (int i = 0; i < sentence.length; i++)
    {
        printf("%s ", sentence.words[i].value);
    }

    printf("\n");
}
