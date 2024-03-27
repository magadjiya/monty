#include "monty.h"
stack_t *temp = NULL;

/**
 * push - pushes an element to the stack
 * @element: pointer to element to be added to stack
 * @line_number: line number of command from buffer
 **/

void push(stack_t **element, unsigned int line_number)
{
	(*element)->next = temp;
	(*element)->prev = NULL;
	if (temp != NULL)
		(*element)->prev = *element;
	temp = *element;
	line_number++;
}

/**
 * pall - displays all the elements in the stack
 * @element: pointer to iterate the stack
 * @line_number: line number of command from buffer
 **/

void pall(stack_t **element, unsigned int line_number)
{
	*element = temp;
	if (*element == NULL)
	{
		fprintf(stderr, "yo");
	}
	else
	{
		while (element != NULL)
		{
			printf("%d\n", (*element)->n);
			*element = (*element)->next;
		}
	}
	line_number++;
}
