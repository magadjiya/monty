#define _GNU_SOURCE
#include "monty.h"


void readfile(char *filename)
{
	FILE *fp;
	char *line = NULL;
	char **command = NULL;
	size_t n = 0;
	int line_number = 1;

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
	}
}
