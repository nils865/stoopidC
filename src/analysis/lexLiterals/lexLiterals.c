#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sentenceComponent/sentenceComponent.h"
#include "../validation/validation.h"

Sentence lexLiterals(Sentence statement)
{
    Word *words = malloc(sizeof(Word) * (statement.length + 1));
    size_t wordLen = 0;

    for (size_t i = 0; i < statement.length; i++, wordLen++)
    {
        if (strcmp(statement.words[i].type, wordTypes[4]) == 0 && strcmp(statement.words[i].value, "\"") == 0)
        {
            Word newWord;
            newWord.type = wordTypes[2];

            printf("Found literal \'\"\' at: %lld\n", i);
            size_t size = strlen(statement.words[i].value) * sizeof(char);
            newWord.value = malloc(size);
            strcpy(newWord.value, statement.words[i].value);


            i++;

            while (i < statement.length)
            {
                newWord.value = realloc(newWord.value, size + (strlen(statement.words[i].value) * sizeof(char)));
                strcat(newWord.value, statement.words[i].value);

                if (strcmp(statement.words[i].value, "\"") == 0)
                {
                    break;
                }

                i++;
            }

            words[wordLen] = newWord;
            continue;
        }

        words[wordLen] = statement.words[i];
    }

    words[wordLen] = (Word) {NULL, NULL};

    Sentence s = wordsToSentence(words);
    printf("Original length %lld | New Length %lld\n", statement.length, s.length);
    
    return s;
}
