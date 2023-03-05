#include <stdio.h>
#include <string.h>

#include "../lexer/lexer.h"
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
    {
        return wordTypes[0];
    }
    else if (arrayIncludes(operators, value))
    {
        return wordTypes[3];
    }
    else if (arrayIncludes(punctuations, value))
    {
        return wordTypes[4];
    }
    else if (arrayIncludes(comments, value))
    {
        return wordTypes[5];
    }
    else
    {
        return "NONE";
    }
}
