#include "monty.h"

/**
 * _tokenize - tokenizes input line from file
 * @line: line to be tokenized
 * Return: the commands without white spaces
 **/

char **_tokenize(char *line, unsigned int line_number, FILE *fp)
{
	char *token =  NULL;
	char **tokens = NULL;
	int i = 0, pos = 0;
	int string_count = 1;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ')
			string_count++;
	}
	if (line_number == 1 && strcmp(line, "pint") == 0)
	{
		free(line);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	tokens = (char **)malloc(sizeof(char *) * (string_count + 1));
	if (tokens == NULL)
	{
		free(line);
		error_malloc();
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[pos] = (char *)malloc(strlen(token) + 1);
		if (tokens[pos] == NULL)
		{
			fprintf(stderr, "Cannot Malloc");
			for (i = 0; i < pos; i++)
				free(tokens[i]);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[pos], token);
		pos++;
		token = strtok(NULL, " ");
	}
	tokens[pos] =  NULL;

	return (tokens);
}
