#include <stdio.h>
#include <stdlib.h>

#include "utils/fileHandling/fileHandling.h"
#include "utils/stringArrayUtils/stringArrayUtils.h"
#include "analysis/lexer/lexer.h"
#include "analysis/lexLiterals/lexLiterals.h"
#include "analysis/wordComponent/wordComponent.h"
#include "analysis/parser/parser.h"
#include "analysis/sentenceComponent/sentenceComponent.h"

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
        printf("\nLexing line: %s\n\n", lines[i]);

        Sentence line = lexln(lines[i]);

        if (line.words[0].value == NULL)
            continue;

        // line = lexLiterals(line);

        outputSentence(line);
        parseStatement(line);
    }

    free(lines);
    free(fileContent);

    return 0;
}
