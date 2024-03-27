#include "main.h"

char **_tokens(char *line)
{
	char *token;
	char **tokens = NULL;
	int pos = 0;
	int string_count = 1;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (command[i] == ' ')
			string_count++;
	}
	tokens = (char **)malloc(sizeof(char *) * (string_count + 1));
	if (tokens == NULL)
	{
		fprintf(stderr, "Cannot Malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(command, " ");
	while (token != NULL)
	{
		tokens[pos] = (char *)malloc(strlen(token) + 1);
		if (tokens[pos] == NULL)
			fprintf(stderr, "Cannot Malloc");
		strcpy(tokens[pos], token);
		pos++;
		token = strtok(NULL, " ");
	}

	tokens[pos] =  NULL;
	free(command);
	return (tokens);
}
