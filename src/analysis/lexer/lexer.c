#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "lexer.h"
#include "../validation/validation.h"
#include "../../utils/stringUtils/stringUtils.h"

Word lexInWord(char *currentWord)
{
    Word word;

    for (size_t i = 0; i < strlen(currentWord); i++)
    {
        word.type = getWordType(trimString(currentWord + i, ' '));

        if (strcmp(word.type, "NONE") != 0)
        {
            word.value = trimString(currentWord + i, ' ');
            return word;
        }
    }

    word.type = getWordType(trimString(currentWord, ' '));
    word.value = trimString(currentWord, ' ');

    return word;
}

Word *lexln(char *line)
{
    printf("\nLexing line: %s\n\n", line);

    Word *words = malloc((strlen(line) + 1) * sizeof(Word));

    char *currentWord = malloc((strlen(line) + 1) * sizeof(char));
    currentWord[0] = '\0';

    for (size_t i = 0; i < strlen(line); i++)
    {
        char currentChar[] = { line[i], '\0' };

        strcat(currentWord, currentChar);
        char *type = getWordType(trimString(currentWord, ' '));
        char *value = trimString(currentWord, ' ');

        Word word;
        word.value = value;
        word.type = type;
        words[i] = word;

        if (strcmp(type, "NONE") == 0 && i != strlen(line) - 1)
        {
            word = lexInWord(currentWord);
            if (strcmp(word.type, "NONE") == 0) continue;
        }

        printf("%s | %s\n", word.value, word.type);

        currentWord = malloc((strlen(line) + 1) * sizeof(char));
        currentWord[0] = '\0';
    }

    free(currentWord);

    return words;
}
