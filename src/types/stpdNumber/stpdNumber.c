#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isNumber(char *str)
{
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1;
}
