#include "../lexer/lexer.h"

const char *keywords[] = {
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

const char *operators[] = {
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

const char *punctuations[] = {
    ":",
    "(",
    ")"
};

const char *comments[] = {
    "#"
};

const char *wordTypes[] = {
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

}
