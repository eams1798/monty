#include "monty.h"

/**
 * check_for_spaces - checks if buffer has spaces or newlines
 * @dest: if src doesn't contain any spaces or newlines, puts here with
 * a newline
 * @src: the string to be checked
 *
 * Return: 1 if src contains at least one space or newline, 0 it doesn't
 */
int check_for_spaces(char *dest, char *src)
{
	char *aux = src;

	while (*aux != ' ' && *aux != '\n')
	{
		if (*aux == '\0')
		{
			strcpy(dest, src);
			strcat(dest, "\n");
			return (0);
		}
		aux++;
	}
	return (1);
}

/**
 * only_one_space - remove extra blank spaces from buffer and puts the result
 * in other string
 * @dest: src puts the string with no extra blank spaces here
 * @src: the string to be cleaned of extra blank spaces
 *
 * Return: Nothing
 */
void only_one_space(char *dest, char *src)
{
	size_t i, size = strlen(src);
	int switcher = 0;

	if (check_for_spaces(dest, src) == 0)
		return;
	for (i = 0; i <= size; i++)
	{
		while (switcher == 0)
		{
			if (*src != ' ')
			{
				dest[i] = *src;
				if (*src == '\n')
					i++;
				src++;
				break;
			}
			if ((*src == ' ')
					&& (*(src + 1) != ' ' && *(src + 1) != '\n'))
			{
				dest[i] = ' ';
				dest[i + 1] = *(src + 1);
				i++;
				src += 2;
				break;
			}
			src++;
		}
		if (*src == '\0')
			switcher = 1;
		if (switcher == 1)
			dest[i] = '\0';
	}
}

/**
 * rm_first_space - checks if the first character of the given string is a
 * blank spaces and deletes if it is
 * @buffer: a buffer to be checked
 *
 * Return: a new buffer with the correct blank spaces
 */
char *rm_first_space(char *buffer)
{
	size_t i;
	char *nofs;

	nofs = malloc(strlen(buffer) * sizeof(char));
	if (nofs == NULL)
	{
		free(nofs);
		return (NULL);
	}
	for (i = 1; i <= strlen(buffer); i++)
	{
		nofs[i - 1] = buffer[i];
	}
	free(buffer);
	return (nofs);
}

/**
 * cure_buffer - Clean buffer of extra blank spaces
 * @buffer: Buffer to process
 *
 * Return: buffer cured
 */
char *cure_buffer(char *buffer)
{
	size_t i, size = strlen(buffer);
	char *j = buffer;
	char *cure = NULL, *aux = NULL;
	char *new = malloc((size + 1) * sizeof(char));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	only_one_space(new, j);
	j = NULL;
	if (new[0] == ' ' || new[0] == '\n')
		aux = rm_first_space(new);
	else
		aux = new;
	if (strlen(aux) == 0)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	cure = malloc((1 + strlen(aux)) * sizeof(char));
	if (cure == NULL)
	{
		free(aux);
		free(cure);
		return (NULL);
	}
	for (i = 0; i < strlen(aux); i++)
		cure[i] = aux[i];
	cure[i] = '\0';
	free(aux);
	new = NULL;
	aux = NULL;
	return (cure);
}
