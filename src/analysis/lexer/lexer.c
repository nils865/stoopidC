#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "../../utils/stringUtils/stringUtils.h"

Word *lexln(char *line)
{
    char **strWords = stringToArray(line, " ");
    outputStringArray(strWords);

    return NULL;
}
