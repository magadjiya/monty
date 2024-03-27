#include "monty.h"

/**
 * push - pushes an element to the stack
 **/

void push(struct_t **element, int line_number)
{

	if (ptr == NULL)
	{
		fprintf("Error: malloc failed")
		exit(EXIT_FAILURE);
	}
	(*element)->next = temp;
	(*element)->prev = NULL;
	if (temp != NULL)
		(*element)->prev = ptr;
	temp = *element;
}
