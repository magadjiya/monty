#include "monty.h"
struct_t temp = NULL;

/**
 * push - pushes an element to the stack
 * @element: pointer to element to be added to stack
 * @line_number: line number of command from buffer
 **/

void push(struct_t **element, int line_number)
{
	(*element)->next = temp;
	(*element)->prev = NULL;
	if (temp != NULL)
		(*element)->prev = *element;
	temp = *element;
}

/**
 * pall - displays all the elements in the stack
 * @element: pointer to iterate the stack
 * @line_number: line number of command from buffer
 **/

void pall(struct_t **element, int line_number)
{
	int i = 0;

	*element = temp;
	if (*element == NULL)
	{
		fprint(stderr, "yo");
	}
	else
	{
		while (element != NULL)
		{
			printf("%d\n", *(element)->n);
			*element = *(element)->next;
		}
	}
}
