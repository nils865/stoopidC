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
    }

    return strArray;
}

void outputStringArray(char *strArray[])
{
    if (strArray == NULL) return;

    int size = sizeof(strArray) / (int) sizeof(strArray[0]);

    printf("size: %d\n", size);

    for (int i = 0; i < size; i++) {
        printf("%s\n", strArray[i]);
    }
}
