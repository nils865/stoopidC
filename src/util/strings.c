#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split(char* str, char splitter)
{
	size_t input_len = strlen(str);
	size_t index = 0;

	char** output = malloc(input_len + 1);
	char* tmpstr = malloc(input_len + 1);

	for (int i = 0; i < input_len + 1; i++)
	{
		char c = str[i];
		if (c == '\0')
			break;
		else if (c == splitter)
		{
			output[index] = malloc(strlen(tmpstr) + 1);
			strcpy(output[index], tmpstr);

			tmpstr = "\0";
			tmpstr = malloc(input_len + 1);
		}
		else
		{
			size_t len = strlen(tmpstr);

			tmpstr[len] = c;
			tmpstr[len + 1] = '\0';
		}
	}

	return output;
}
