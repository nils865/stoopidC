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

    // outputStringArray(lines);
    // printf("%s\n", lexln(lines[0])[0].value);   hello   
    Word *words = lexln(lines[0]);

    return 0;
}
