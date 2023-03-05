#include <stdio.h>
#include <stdlib.h>

#include "utils/fileHandling/fileHandling.h"
#include "utils/stringArrayUtils/stringArrayUtils.h"
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

        Word currentWord;

        for (size_t j = 0; ((currentWord = line[j]).value != NULL); j++)
        {
            printf("Word: %s | Type: %s\n", currentWord.value, currentWord.type);
        }
    }

    free(lines);
    free(fileContent);

    return 0;
}
