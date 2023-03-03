#include <stdio.h>
#include <stdlib.h>

#include "utils/fileHandling/fileHandling.h"

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("No filename given!\n");
        return 1;
    }

    char *fileContent = loadFile(argv[1]);

    printf("%s", fileContent);

    return 0;
}
