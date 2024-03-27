#include "monty.h"


void readfile(char *filename)
{
	FILE *fp;
	char *line;
	char **command;
	int line_number = 1;
	char **tokens = NULL;

	fp = open(filename, "rw");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open file &s", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, 100, fp) != EOF)
	{
		command = _tokenize(line);
		opcodes(command, line_number);
		line_number++;
	}
}
