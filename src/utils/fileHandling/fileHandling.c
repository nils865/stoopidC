#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 20

char *loadFile(char *fileName)
{
    // load file
    FILE *file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    // read file
    char ch;
    size_t lineSize = DEFAULT_SIZE;
    char *fileContent = (char*) malloc(lineSize * sizeof(char));

    while ((ch = fgetc(file)) != EOF)
    {
        char str[] = { ch, '\0' };

        if (strlen(fileContent) + 2 >= lineSize)
            fileContent = (char*) realloc(fileContent, (lineSize *= 2) * sizeof(char));

        strcat(fileContent, str);
    }

    return fileContent;
}
