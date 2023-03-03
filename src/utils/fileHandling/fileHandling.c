#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **loadFile(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    return NULL;
}
