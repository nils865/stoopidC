#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void read_file(char** name) {
    FILE *file = fopen(*name, "rb");

    if (file == NULL) {
        printf("File %s not found\n", *name);
        return;
    }

    printf("found\n");

}
