#include "monty.h"
#define MAX_READ 100


void readfile(char *filename)
{
	FILE *fp;
	char *line;
	char **command;
	int line_number = 1;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open file %s", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, MAX_READ, fp) != EOF)
	{
		command = _tokenize(line);
		opcodes(command, line_number);
	}
}
