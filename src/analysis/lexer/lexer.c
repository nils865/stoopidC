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
        char *value = trimString(currentWord, ' ');

        if (strcmp(type, "NONE") == 0 && i != strlen(line) - 1)
        {
            int found = 0;

            for (size_t j = 0; j < strlen(currentWord); j++)
            {
                type = getWordType(trimString(currentWord + j, ' '));

                if (strcmp(type, "NONE") != 0)
                {
                    value = trimString(currentWord + j , ' ');
                    found = 1;
                    break;
                }
            }

            if (found == 0) continue;
        }

        Word word;
        word.value = value;
        word.type = type;
        words[i] = word;

        printf("%s | %s\n", word.value, word.type);

        currentWord = malloc((strlen(line) + 1) * sizeof(char));
        currentWord[0] = '\0';
    }

    free(currentWord);

    return words;
}
