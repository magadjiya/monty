#include "monty.h"

/**
 * push - pushes an element to the stack
 **/

void push(int *element)
{
	struct_t *ptr;

	ptr = malloc(sizeof(struct_t));
	if (ptr == NULL)
	{
		fprintf("Error: malloc failed")
		exit(EXIT_FAILURE);
	}
	ptr->n = element;
	ptr->next = temp;
	ptr->prev = NULL;
	if (temp != NULL)
		ptr->prev = ptr;
	temp = ptr;
}
