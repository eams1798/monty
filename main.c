#include "monty.h"

/**
 * main - monty language's interpreter
 * @argc: number of arguments
 * @argv: arguments of the program
 *
 * Return: EXIT_SUCCESS if the whole given file could be read,
 * and EXIT_FAILURE if not
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	switch (argc)
	{
		/*
		 * case 1:
		 * printf("Monty shell: coming soon\n");
		 * break;
		 */
		case 2:
			if (strcmp(extension(argv[1]), ".m") != 0)
			{
				write(2, "USAGE: monty <file>.m\n", 22);
				exit(EXIT_FAILURE);
			}
			else
			{
				read_file(argv[1], &stack);
				free_stack(stack);
			}
			break;
		default:
			write(2, "USAGE: monty file\n", 18);
			exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
