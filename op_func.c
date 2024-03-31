#include "monty.h"
stack_t *temp = NULL;

/**
 * push - pushes an element to the stack
 * @element: pointer to element to be added to stack
 * @line_number: line number of command from buffer
 **/

void push(stack_t **element, unsigned int line_number)
{
	if (line_number)
	{
		(*element)->next = temp;
		(*element)->prev = NULL;
		if (temp != NULL)
			(*element)->prev = *element;
		temp = *element;
	}
}

/**
 * pall - displays all the elements in the stack
 * @element: pointer to iterate the stack
 * @line_number: line number of command from buffer
 **/

void pall(stack_t **element, unsigned int line_number)
{
	if (line_number)
	{
		*element = temp;
		if (*element == NULL)
		{
			;
		}
		else
		{
			while (*element != NULL)
			{
				printf("%d\n", (*element)->n);
				*element = (*element)->next;
			}
		}
	}
}

/**
 * pint - prints the value at the top of the stack
 * @element: stack
 * @line_number: line number in file
 **/

void pint(stack_t **element, unsigned int line_number)
{
	unsigned int i = 0;
        *element = temp;
        if (temp == NULL)
        {
                fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		for (i = 0; element[i] != NULL; i++)
			free(element[i]);
		free(element);
        }
        printf("%d\n", (*element)->n);
}
