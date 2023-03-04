#include <string.h>
#include <stdlib.h>

#include "lexer.h"

Word *lexln(char *line)
{
    Word *words = malloc(sizeof(Word));
    char *word = strtok(line, " ");

    return words;
}
