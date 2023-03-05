#include <stdlib.h>
#include <string.h>

char *trimString(char *str, char trimmer)
{
    char *newStr = malloc((strlen(str) + 1) * sizeof(char));

    size_t start, end;

    for (start = 0; str[start] == trimmer; start++);

    if (str[start] == '\0')
    {
        newStr[0] = '\0';
        return newStr;
    }

    for (end = strlen(str) - 1; str[end] == trimmer; end--);

    for (size_t i = start; i <= end; i++)
    {
        newStr[i - start] = str[i];

        if (i == end) newStr[i - start + 1] = '\0';
    }

    return newStr;
}

char *reverseString(char *str)
{
    char *newStr = malloc((strlen(str) + 1) * sizeof(char));
    newStr[0] = '\0';

    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        newStr[strlen(str) - i - 1] = str[i];

        if (i == 0) newStr[strlen(str)] = '\0';
    }

    return newStr;
}
