#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../validation/validation.h"

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

Word lexFloat()
{
    Word word;
    word.type = wordTypes[2];

    return word;
}
