#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "lexer.h"
#include "../validation/validation.h"
#include "../../utils/stringUtils/stringUtils.h"

Word *lexln(char *line)
{
    Word *words = malloc((strlen(line) + 1) * sizeof(Word));

    char *currentWord = malloc((strlen(line) + 1) * sizeof(char));
    currentWord[0] = '\0';

    for (size_t i = 0; i < strlen(line); i++)
    {
        char currentChar[] = { line[i], '\0' };

        strcat(currentWord, currentChar);
        char *type = getWordType(trimString(currentWord, ' '));

        if (strcmp(type, "NONE") == 0 && i != strlen(line) - 1)
            continue;

        Word word;
        word.value = trimString(currentWord, ' ');
        word.type = type;
        words[i] = word;

        printf("%s | %s\n", word.value, word.type);

        currentWord = malloc((strlen(line) + 1) * sizeof(char));
        currentWord[0] = '\0';
    }

    free(currentWord);

    return words;
}
