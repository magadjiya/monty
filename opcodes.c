#include "monty.h"

/**
 * opcodes - operation codes
 * @command: the command given
 * @line_number: the current line the interpreter is implementing
 * @line: address of line from getline
 * @fp: file pointer
 **/
void opcodes(char **command, unsigned int line_number,
	     char *line, FILE *fp)
{
	int i = 0, count = 0, num_instructions = 0;
	stack_t *element = NULL;
	instruction_t arr[] = {{"push", push}, {"pall", pall},
			       {"pint", pint}};

	num_instructions = sizeof(arr) / sizeof(arr[0]);
	while (command != NULL && command[count] != NULL)
		count++;
	for (i = 0; i < num_instructions; i++)
	{
		if (command[0] == NULL)
		{
			return;
		}
		if (strcmp(command[0], arr[i].opcode) == 0)
		{
			if (i == 0)
			{
			if (count < 2)
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
				error_command(command, element, line, fp);
			}
			element = malloc(sizeof(stack_t));
			if (element == NULL)
				error_malloc();
			is_digit(command, element, line_number, count, line, fp);
			element->n = atoi(command[1]);
			}
			arr[i].f(&element, line_number);
			return;
		}
	}
	error_invalid_cmd(element, line_number, command[0]);
}

/**
 * is_digit - checks if the second token is a digit
 * @command: command tokens
 * @element: stack
 * @line_number: line number in file
 * @count: number of tokens in input
 * @line: line from getline
 * @fp: file pointer
 **/

void is_digit(char **command, stack_t *element,
	      unsigned int line_number, int count, char *line, FILE *fp)
{
	int i = 0;

	if (count > 1)
	{
		for (i = 0; command[1][i] != '\0'; i++)
		{
			if (command[1][i] != '0' && atoi(command[1]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
				error_command(command, element, line, fp);
			}
		}
	}

}
