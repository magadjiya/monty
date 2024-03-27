#include "monty.h"

/**
 *
 **/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	readfile(argv[1]);

	return (0)
}
