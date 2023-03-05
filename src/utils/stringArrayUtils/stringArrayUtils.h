#ifndef STRING_ARRAY_UTILS_H
#define STRING_ARRAY_UTILS_H

#include <stdlib.h>

char **stringToArray(char *str, char splitter[1]);

void outputStringArray(char *arr[]);

size_t getStringArraySize(char **strArray);

int arrayIncludes(char **arr, char *str);

#endif
