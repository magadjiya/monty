#define _GNU_SOURCE
#include "monty.h"


void readfile(char *filename)
{
	FILE *fp;
	char *line;
	char **command;
	size_t n = 0;
	int line_number = 1;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, fp) != EOF)
	{
		command = _tokenize(line);
		opcodes(command, line_number);
	}
}
