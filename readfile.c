#define _GNU_SOURCE
#include "monty.h"


void readfile(char *filename)
{
	FILE *fp;
	char *line = NULL;
	char **command = NULL;
	size_t n = 0;
	int line_number = 1, i = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fp) != EOF)
	{
		line[strcspn(line, "\n")] = '\0';
		command = _tokenize(line);
		opcodes(command, line_number);
		for (i = 0; command[i] != NULL; i++)
			free(command[i]);
		free(command);
		free(temp);
		command = NULL;
	}
	free(line);
	line = NULL;
	temp = NULL;
	fclose(fp);
}
