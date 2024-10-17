#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* read_file(char** name) {
    FILE *file = fopen(*name, "rb");

    if (file == NULL) {
        printf("File %s not found\n", *name);
        return NULL;
    }

    size_t buffer_size = 2048;
    size_t read_size = 0;
    size_t total_size = 0;

    char* buffer = malloc(buffer_size);

    read_size = fread(buffer + total_size, 1, buffer_size - total_size, file);

    while (read_size > 0) {
        total_size += read_size;

        if (total_size == buffer_size) {
            buffer_size *= 2;

            char* new_buffer = realloc(buffer, buffer_size);

            buffer = new_buffer;
        }

        read_size = fread(buffer + total_size, 1, buffer_size - total_size, file);
    }

    return buffer;
}
