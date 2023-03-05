#include <stdio.h>
#include <string.h>

#include "../wordComponent/wordComponent.h"
#include "../../utils/stringArrayUtils/stringArrayUtils.h"

char *keywords[] = {
    "var",
    "arr",
    "out",
    "goto",
    "sleep",
    "goif",
    "if",
    "end",
    "exit",
    NULL
};

char *operators[] = {
    "+",
    "-",
    "*",
    "/",
    "%",
    "^",
    "=",
    "!",
    ">",
    "<",
    "&",
    "|",
    NULL
};

char *punctuations[] = {
    ":",
    "(",
    ")",
    "\"",
    NULL
};

char *comments[] = {
    "#",
    NULL
};

char *wordTypes[] = {
    "Keyword",
    "Identifier",
    "Literal",
    "Operator",
    "Punctuation",
    "Comment",
    NULL
};

char *getWordType(char *value)
{
    if (arrayIncludes(keywords, value))
        return wordTypes[0];
    else if (arrayIncludes(operators, value))
        return wordTypes[3];
    else if (arrayIncludes(punctuations, value))
        return wordTypes[4];
    else if (arrayIncludes(comments, value))
        return wordTypes[5];
    else
        return "NONE";
}

Word validateComment(Word commentPrefix, char *comment)
{
    if (arrayIncludes(comments, commentPrefix.value) == 0)
        return (Word) { NULL, NULL };
    else
    {
        Word w;

        w.type = wordTypes[5];

        w.value = malloc((strlen(comment) + strlen(commentPrefix.value)) * sizeof(char));
        w.value = strcpy(w.value, commentPrefix.value);
        w.value = strcat(w.value, comment);

        return w;
    }
}
