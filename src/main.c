#include "../include/interpreter/tokens.h"
#include "../include/utils/file_io.h"
#include "../include/utils/strings.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	char* filename;

	for (int i = 1; i < argc; i++)
	{
		char* arg = argv[i];

		if (arg[0] == '-')
		{
			// is cli argument
		}
		else
		{
			filename = arg;
		}
	}

	if (filename == NULL)
	{
		return 1;
	}

	char* content = read_file(&filename);

	char** lines = split(content, '\n');

	for (int i = 0; i < (sizeof(lines) / sizeof(char*)); i++)
	{
		printf("%s\n", lines[i]);
	}

	return 0;
}
