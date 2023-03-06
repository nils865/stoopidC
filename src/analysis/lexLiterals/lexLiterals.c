#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sentenceComponent/sentenceComponent.h"
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

        if (strcmp(currentChar, "\"") == 0)
            break;

        *i += 1;
    }

    printf("Literal Word: %s\n", word.value);

    return word;
}

void literalString(Sentence *statement, size_t *i, Word **words, size_t *wordLen)
{
    Word newWord;
    newWord.type = wordTypes[2];

    size_t size = strlen(statement->words[*i].value) * sizeof(char);
    newWord.value = malloc(size);
    strcpy(newWord.value, statement->words[*i].value);

    *i += 1;

    while (*i < statement->length)
    {
        newWord.value = realloc(newWord.value, size += (strlen(statement->words[*i].value) * sizeof(char)));
        strcat(newWord.value, statement->words[*i].value);

        if (strcmp(statement->words[*i].value, "\"") == 0)
            break;

        *i += 1;
    }

    (*words)[*wordLen] = newWord;
}

Sentence lexLiterals(Sentence statement)
{
    Word *words = malloc(sizeof(Word) * (statement.length + 1));
    size_t wordLen = 0;

    for (size_t i = 0; i < statement.length; i++, wordLen++)
    {
        if (strcmp(statement.words[i].type, wordTypes[4]) == 0 && strcmp(statement.words[i].value, "\"") == 0)
        {
            literalString(&statement, &i, &words, &wordLen);
            continue;
        }

        words[wordLen] = statement.words[i];
    }

    words[wordLen] = (Word) {NULL, NULL};

    Sentence s = wordsToSentence(words);
    
    return s;
}
