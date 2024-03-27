#include "monty.h"

/**
 * main - monty interpreter
 * @ac: argument count
 * av: argument vector
 **/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	readfile(av[1]);

	return (0);
}
