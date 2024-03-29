#ifndef HEADER_FILE
#define HEADER_FILE

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *temp;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void push(stack_t **element, unsigned int line_number);
void pall(stack_t **element, unsigned int line_number);
void opcodes(char **command, unsigned int line_number, char *line, FILE *fp);
void readfile(char *filename);
char **_tokenize(char *line);
void error_malloc(void);
void error_command(char **command, stack_t *element,
		   unsigned int line_number, char * line, FILE *fp);
void error_invalid_cmd(stack_t *element, unsigned int line, char *cmd);
void _free(char *, FILE *fp);
void is_digit(char **command, stack_t *, unsigned int line_number,
	      int count, char *line, FILE *fp);

#endif /* MONTY_H */
