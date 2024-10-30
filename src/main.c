#include <stdio.h>
#include "../include/file_io.h"
#include "../include/interpreter/tokens.h"

int main(int argc, char* argv[]) {
    char* filename;

    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];

        if (arg[0] == '-') {
            // is cli argument
        } else {
            filename = arg;
        }
    }

    if (filename == NULL) {
        return 1;
    }

    char* content = read_file(&filename);

    printf("%s\n", content);

    enum Token t = KEYWORD;

    printf("%d\n", t);

    return 0;
}
