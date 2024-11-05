#ifndef TOKENS_H
#define TOKENS_H

enum Token
{
	KEYWORD,
	LITERAL,
	OPERATOR,
	PUNKTUATION,
	COMMENT,
	BRACKET
};

struct Tokenized
{
	char* value;
	enum Token type;
};

#endif
