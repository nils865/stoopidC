#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../wordComponent/wordComponent.h"
#include "../validation/validation.h"
#include "../sentenceComponent/sentenceComponent.h"
#include "../lexLiterals/lexLiterals.h"
#include "../../utils/stringUtils/stringUtils.h"
#include "../../types/stpdNumber/stpdNumber.h"
#include "../../types/stpdBool/stpdBool.h"

Word lexInWord(char *currentWord)
{
    Word word;

    for (size_t i = 0; i < strlen(currentWord); i++)
    {
        word.type = getWordType(trimString(currentWord + i, ' '));

        if (strcmp(word.type, wordTypes[6]) != 0)
        {
            word.value = trimString(currentWord + i, ' ');
            return word;
        }
    }

    word.type = getWordType(trimString(currentWord, ' '));
    word.value = trimString(currentWord, ' ');

    return word;
}

Word lexPreviousWord(char *currentWord, char *suffix)
{
    char *currentWordReversed = reverseString(currentWord);
    char *suffixReversed = reverseString(suffix);

    Word w = { NULL, NULL };

    if (strncmp(currentWordReversed, suffixReversed, strlen(suffixReversed)) == 0)
    {
        char *value = malloc((strlen(currentWord) - strlen(suffix) + 1) * sizeof(char));
        strncpy(value, currentWord, strlen(currentWord) - strlen(suffix));

        w.type = getWordType(trimString(value, ' '));
        w.value = trimString(value, ' ');

        free(value);
    }

    free(currentWordReversed);
    free(suffixReversed);

    return w;
}

Sentence lexln(char *line)
{
    Word *words = malloc((strlen(line) + 1) * sizeof(Word));
    int wordCount = 0;

    char *currentWord = malloc((strlen(line) + 1) * sizeof(char));
    currentWord[0] = '\0';

    for (size_t i = 0; i < strlen(line); i++)
    {
        char currentChar[] = { line[i], '\0' };

        strcat(currentWord, currentChar);
        char *type = getWordType(trimString(currentWord, ' '));
        char *value = trimString(currentWord, ' ');

        Word word;
        word.value = value;
        word.type = type;

        if (strcmp(type, wordTypes[4]) == 0 && strcmp(value, "\"") == 0)
            word = lexString(line, &i);
        else if (i != strlen(line) - 1)
        {
            if (strcmp(type, wordTypes[6]) == 0 && i != strlen(line) - 1)
            {
                word = lexInWord(currentWord);
                if (strcmp(word.type, wordTypes[6]) == 0) continue;
                int addPreviousWord = 1;

                Word previousWord = lexPreviousWord(currentWord, word.value);

                if (strcmp(previousWord.type, wordTypes[6]) == 0 && isNumber(previousWord.value))
                {
                    if (strcmp(word.type, wordTypes[4]) == 0 && strcmp(word.value, punctuations[4]) == 0)
                    {
                        word = lexFloat(&previousWord, &word, line, &i);
                        addPreviousWord = 0;
                    }
                    else
                        lexInt(&previousWord);
                }


                if (addPreviousWord)
                {
                    if (strcmp(previousWord.type, wordTypes[6]) == 0 && isBool(previousWord.value))
                        previousWord.type = wordTypes[2];
                    
                    words[wordCount] = previousWord;
                    wordCount++;
                }
            }
        }
        else
        {
            Word newWord = validateComment(words[wordCount - 1], currentWord);

            if (newWord.value != NULL)
            {
                wordCount--;
                continue;
            }
            else if (strcmp(word.type, wordTypes[6]) == 0)
            {
                if (isNumber(word.value))
                    lexInt(&word);
                else if (isBool(word.value))
                    word.type = wordTypes[2];
            }
        }

        words[wordCount] = word;
        wordCount++;

        currentWord = malloc((strlen(line) + 1) * sizeof(char));
        currentWord[0] = '\0';
    }

    words[wordCount] = (Word) { NULL, NULL };

    free(currentWord);

    Sentence sentence = wordsToSentence(words);

    return sentence;
}
