#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 5

char **loadFile(char *filename)
{
    // load file
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    // read file
    char ch;
    size_t lineSize = DEFAULT_SIZE;
    char *currentLine = (char*)malloc(lineSize * sizeof(char));
    currentLine[0] = '\0';

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            printf("%s\n", currentLine);
            currentLine = (char*)malloc(lineSize * sizeof(char));
            currentLine[0] = '\0';
            lineSize = DEFAULT_SIZE;
            continue;
        }

        if (strlen(currentLine) + 1 >= lineSize)
            currentLine = (char*)realloc(currentLine, (lineSize *= 2) * sizeof(char));

        char str[] = { ch , '\0' };

        strcat(currentLine, str);
    }

    return NULL;
}
