#ifndef LEXER_H
#define LEXER_H

typedef struct
{
    char *type;
    char *value;
} Word;

Word *lexln(char *line);

#endif
