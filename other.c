#include "monty.h"

/**
 * extension - checks the extension of a file
 * @file: the name of a file
 *
 * Return: the extension of a file
 */
char *extension(char *file)
{
	char *ext;
	int i = 0;

	if (file == NULL)
		return (NULL);
	while (file[i] != '\0')
		i++;
	i--;
	ext = file + i;
	while (*ext != '.' && i >= 0)
	{
		ext--;
		i--;
	}
	return (ext);
}

/**
 * free_args - frees a buffer which contains all the token arguments of a line
 * @args: the given buffer
 *
 * Return: Nothing
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
		i++;
	i--;
	for (; i >= 0; i--)
		free(args[i]);
	free(args);
	args = NULL;
}

/**
 * free_stack - frees a stack
 * @stack: a doubly linked list which is working as a stack
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;
	if (stack->next != NULL)
		free_stack(stack->next);
	free(stack);
}

/**
 * isnumber - checks if the given string is a number
 * @s: a string
 *
 * Return: 1 if 's' is a number, or 0 if it isn't
 */
int isnumber(char *s)
{
	char *n = s;

	if (n == NULL)
		return (0);
	while (*n != '\0')
	{
		if (*n < 48 || *n > 57)
			return (0);
		n++;
	}
	return (1);
}
