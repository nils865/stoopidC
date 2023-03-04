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

    printf("%d\n", arrayIncludes(keywords, value));

}
