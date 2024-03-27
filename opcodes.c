#include "monty.h"

void opcodes(char **command, unsigned int line_number)
{
	int i = 0, count = 0;
	stack_t *element;
	instruction_t arr[] = {{"push", push}, {"pall", pall}};

	while (command[count] != NULL)
		count++;
	element = malloc(sizeof(stack_t));
	if (element == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (count > 1)
	{
		for (i = 0; command[1][i] != '\0'; i++)
		{
			if (!(command[1][i] >= '0' && command[1][i] <= '9'))
			{
				fprintf(stderr, "L%d: usage: push integer",
					line_number);
				exit(EXIT_FAILURE);
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		if (strcmp(command[0], arr[i].opcode) == 0)
		{
			if (i == 0)
			{
				if (count < 2)
				{
					fprintf(stderr,
						"L%d: usage: push integer",
						line_number);
					exit(EXIT_FAILURE);
				}
				element->n = atoi(command[1]);
			}
			arr[i].f(&element, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s",
				line_number, arr[i].opcode);
			exit(EXIT_FAILURE);
		}
	}
}
