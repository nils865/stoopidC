#include <stdio.h>

#include "../lexer/lexer.h"
#include "../../utils/stringUtils/stringUtils.h"

char *keywords[] = {
    "var",
    "arr",
    "out",
    "goto",
    "sleep",
    "goif",
    "if",
    "end",
    "exit"
};

char *operators[] = {
    "+",
    "-",
    "*",
    "/",
    "%",
    "^",
    "==",
    "!=",
    ">",
    "<",
    ">=",
    "<=",
    "and",
    "or",
    "not"
};

char *punctuations[] = {
    ":",
    "(",
    ")"
};

char *comments[] = {
    "#"
};

char *wordTypes[] = {
    "Keyword",
    "Identifier",
    "Literal",
    "Operator",
    "Punctuation",
    "Comment"
};

void setWordType(Word *word)
{
    char *value = word->value;

    if (arrayIncludes(keywords, value))
    {
        word->type = wordTypes[0];
    }
    else if (arrayIncludes(operators, value))
    {
        word->type = wordTypes[3];
    }
    else if (arrayIncludes(punctuations, value))
    {
        word->type = wordTypes[4];
    }
    else if (arrayIncludes(comments, value))
    {
        word->type = wordTypes[5];
    }
    else
    {
        word->type = "NONE";
    }
}
