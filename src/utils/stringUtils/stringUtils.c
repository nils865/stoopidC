#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **stringToArray(char *str, char splitter[1])
{
    char *currentString;
    char **strArray = malloc(sizeof(char*));

    currentString = strtok(str, splitter);

    for (size_t i = 0; currentString != NULL; i++)
    {
        strArray = (char**) realloc(strArray, (i + 2) * sizeof(char*));
        strArray[i] = (char*) malloc(strlen(currentString) + 1);

        strcpy(strArray[i], currentString);

        currentString = strtok(NULL, splitter);

        if (currentString == NULL)
        {
            strArray[i + 1] = NULL;
        }
    }

    return strArray;
}

size_t getStringArraySize(char **strArray)
{
    if (strArray == NULL) return 0;

    size_t size = 0;

    while (strArray[size] != NULL) size++;

    return size;
}

void outputStringArray(char **strArray)
{
    if (strArray == NULL) return;

    for (size_t i = 0; i < getStringArraySize(strArray); i++)
    {
        printf("%s\n", strArray[i]);
    }
}

int arrayIncludes(char **arr, char *str)
{
    if (arr == NULL) return 0;

    for (size_t i = 0; i < getStringArraySize(arr); i++)
    {
        if (strcmp(arr[i], str) == 0) return 1;
    }

    return 0;
}

char *trimString(char *str, char trimmer)
{
    printf("string %s\n", str);

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
