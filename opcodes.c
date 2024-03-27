#include "monty.h"

void opcodes(char **command, int line_number)
{
	int i = 0;
	struct_t element;

	element = malloc(sizeof(struct_t));
	if (element = NULL)
	{
		fprinf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	instruction_t arr[] = {{"push", push}, {"pall", pall}};

	for (i = 0; command[1][i] != '\0'; i++)
	{
		if !(command[1][i] >= '0' && command[i] <= '9')
		{
			fprintf(stderr, "invalid command");
			exit(EXIT_FALURE);
		}
	}
	element->n = atoi(command[1]);
	for (i = 0; arr[i] < 2; i++)
	{
		if (strcmp(command[0], arr[i]->opcode) == 0)
		{
			arr[i]->(*f)(&element, line_number);
		}
	}
}
