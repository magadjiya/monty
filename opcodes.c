#include "monty.h"

/**
 * opcodes - operation codes
 * @command: the command given
 * @line_number: the current line the interpreter is implementing
 */
void opcodes(char **command, unsigned int line_number)
{
	int i = 0, count = 0, num_instructions = 0;
	stack_t *element;
	instruction_t arr[] = {{"push", push}, {"pall", pall}};

	num_instructions = sizeof(arr) / sizeof(arr[0]);
	while (command[count] != NULL)
		count++;
	element = malloc(sizeof(stack_t));
	if (element == NULL)
		error_malloc();

	if (count > 1)
	{
		for (i = 0; command[1][i] != '\0'; i++)
		{
			if (!(command[1][i] >= '0' && command[1][i] <= '9'))
				error_command(element, line_number);
		}
	}
	for (i = 0; i < num_instructions; i++)
	{
		if (strcmp(command[0], arr[i].opcode) == 0)
		{
			if (i == 0)
			{
				if (count < 2)
					error_command(element, line_number);
				element->n = atoi(command[1]);
			}
			arr[i].f(&element, line_number);
			return;
		}
	}

	error_invalid_cmd(element, line_number, command[0]);
	free(element);
	free(command);
}
