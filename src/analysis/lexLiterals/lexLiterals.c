#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../validation/validation.h"
#include "../../types/stpdNumber/stpdNumber.h"

Word lexString(char *line, size_t *i)
{
    Word word;
    word.type = wordTypes[2];

    size_t size = strlen(line + *i) * sizeof(char);
    word.value = malloc(size);
    char currentChar[2] = { line[*i], '\0' };
    strcpy(word.value, currentChar);
    *i += 1;

    while (*i < strlen(line))
    {
        currentChar[0] = line[*i];
        word.value = realloc(word.value, size += sizeof(char));
        strcat(word.value, currentChar);

        *i += 1;

        if (strcmp(currentChar, "\"") == 0)
            break;
    }

    return word;
}

void lexInt(Word *word)
{
    word->type = wordTypes[2];
}

Word lexFloat(Word *previousWord, Word *currentWord, char *line, size_t *i)
{
    if (strcmp(previousWord->type, wordTypes[6]) != 0 || isNumber(previousWord->value) == 0 || strcmp(currentWord->type, wordTypes[4]) != 0 || strcmp(currentWord->value, punctuations[4]) != 0)
        return (Word) {NULL, NULL};
    
    Word word;
    word.type = wordTypes[2];
    
    size_t size = (strlen(previousWord->value) + strlen(currentWord->value)) * sizeof(char);
    word.value = malloc(size);
    strcpy(word.value, previousWord->value);
    strcat(word.value, currentWord->value);

    char digit = line[*i + 1];

    while (isdigit(digit) && *i < strlen(line))
    {
        char currentChar[2] = { digit, '\0' };
        word.value = realloc(word.value, size += sizeof(char));
        strcat(word.value, currentChar);

        *i += 1;
        if(*i < strlen(line))
            digit = line[*i + 1];
    }


    return word;
}
