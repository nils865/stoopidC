#include <string.h>
#include <stdlib.h>

#include "lexer.h"
#include "../validation/validation.h"
#include "../../utils/stringUtils/stringUtils.h"

Word *lexln(char *line)
{
    char **strWords = stringToArray(line, " ");
    outputStringArray(strWords);

    Word w1;
    w1.value = "var";
    setWordType(&w1);

    Word w2;
    w2.value = "ccc";
    setWordType(&w2);

    return NULL;
}
