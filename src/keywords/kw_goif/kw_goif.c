#include <string.h>

#include "../../analysis/sentenceComponent/sentenceComponent.h"
#include "../../analysis/validation/validation.h"

int kw_goif_grammar(Sentence statement)
{
    for (size_t i = 0; i < statement.length; i++)
    {
        if (i == 0 && strcmp(statement.words[i].type, wordTypes[0]) != 0)
            return 1;
        else if (i == 1 && strcmp(statement.words[i].type, wordTypes[4]) != 0)
            return 1;
        else if (i == 2 && strcmp(statement.words[i].type, wordTypes[2]) != 0)
            return 1;
        else if (i == 3 && strcmp(statement.words[i].type, wordTypes[4]) != 0)
            return 1;
        else if (i > 3 && (strcmp(statement.words[i].type, wordTypes[0]) == 0 || strcmp(statement.words[i].type, wordTypes[5]) == 0 || strcmp(statement.words[i].type, wordTypes[6]) == 0))
            return 1;
    }

    return 0;
}
