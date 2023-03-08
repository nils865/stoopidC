#include <string.h>

int isBool(char *str)
{
    return (strcmp(str, "true") == 0 || strcmp(str, "false") == 0);
}
