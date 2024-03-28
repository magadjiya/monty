#define _GNU_SOURCE
#include "monty.h"

/**
 * readfile - opens a file in read mode and reads it line by line
 * @filename: name of the file to be read
 */
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
		if (strcmp(line, "\n") == 0)
			getline(&line, &n, fp);
		line[strcspn(line, "\n")] = '\0';
		command = _tokenize(line);
		opcodes(command, line_number);
		for (i = 0; command[i] != NULL; i++)
			free(command[i]);
		free(command);
		command = NULL;
	}
	_free(line, fp);
}

/**
 * _free - free all dynamically allocated memory
 * @line: from getline
 * @fp: file handler
 **/

void _free(char *line, FILE *fp)
{
	stack_t *holder;

	while (temp != NULL)
	{
		holder = temp->next;
		free(temp);
		temp = holder;
	}
	free(line);
	line = NULL;
	fclose(fp);
}
