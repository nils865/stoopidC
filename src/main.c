#include <stdio.h>
#include <stdlib.h>

#include "utils/fileHandling/fileHandling.h"
#include "utils/stringUtils/stringUtils.h"
#include "analysis/lexer/lexer.h"

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("No filename given!\n");
        return 1;
    }

    char *fileContent = loadFile(argv[1]);
    char **lines = stringToArray(fileContent, "\n");

    for (size_t i = 0; i < getStringArraySize(lines); i++)
    {
        Word *line = lexln(lines[i]);
    }

    free(lines);
    free(fileContent);

    return 0;
}
