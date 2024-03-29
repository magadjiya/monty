#include "monty.h"

/**
 * error_malloc - handles malloc fail
 */
void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * error_command - handles wrong
 * @command: command passed
 * @element: struct integer to implement the command on
 * @line_number: the line at which error occurs
 * @line: line from getline
 * @fp: file pointer
 */
void error_command(char **command, stack_t *element,
		   unsigned int line_number, char *line, FILE *fp)
{
	stack_t *holder = temp;
	int i = 0;

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	while (temp != NULL)
	{
		holder = temp->next;
		free(temp);
		temp = holder;
	}
	free(element);
	element = NULL;
	for (i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
		command[i] = NULL;
	}
	free(command);
	command = NULL;
	free(line);
	fclose(fp);
	exit(EXIT_FAILURE);
}

/**
 * error_invalid_cmd - handles unknown instructions
 * @element: struct integer to implement the cmd on
 * @line: the line number of the error
 * @cmd: the instruction given
 */
void error_invalid_cmd(stack_t *element, unsigned int line, char *cmd)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
	free(element);
	exit(EXIT_FAILURE);
}
