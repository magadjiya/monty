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
 * @element: struct integer to implement the command on
 * @line_number: the line at which error occurs
 */
void error_command(stack_t *element, unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free(element);
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
	fprintf(stderr, "L%d: unknown instruction %s", line, cmd);
	free(element);
	exit(EXIT_FAILURE);
}
