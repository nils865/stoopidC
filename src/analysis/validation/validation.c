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
    "=",
    "!",
    ">",
    "<",
    "&",
    "|",
};

char *punctuations[] = {
    ":",
    "(",
    ")",
    "\""
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
