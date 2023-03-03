#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **stringToArray(char *str)
{
    char *currentString;
    char **strArray = NULL;

    currentString = strtok(str, "\n");

    for (size_t i = 0; currentString != NULL; i++)
    {
        strArray = (char**) realloc(strArray, (i + 1) * sizeof(char*));
        strArray[i] = (char*) malloc(strlen(currentString) + 1);

        strcpy(strArray[i], currentString);

        currentString = strtok(NULL, "\n");

        if (currentString == NULL)
        {
            strArray[i + 1] = NULL;
        }
    }

    return strArray;
}

void outputStringArray(char **strArray)
{
    if (strArray == NULL) return;

    size_t size = 0;
    while (strArray[size] != NULL) size++;

    for (size_t i = 0; i < size; i++)
    {
        printf("%s\n", strArray[i]);
    }
}
