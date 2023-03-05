#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdlib.h>

char **stringToArray(char *str, char splitter[1]);

void outputStringArray(char *arr[]);

size_t getStringArraySize(char **strArray);

int arrayIncludes(char **arr, char *str);

char *trimString(char *str, char trimmer);

char *reverseString(char *str);

#endif
