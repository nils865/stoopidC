#include <stdio.h>
#include "../include/file_io.h"

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

    printf("File content: %s\n", content);

    return 0;
}
