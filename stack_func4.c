#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @stack: a given stack
 * @line: the index of the current line
 *
 * Return: Nothing
 */
void _queue(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;

	montyflag = 1;
	statusfunc = 1;
}

/**
 * _stack - sets the format of the data to a queue (FIFO)
 * @stack: a given stack
 * @line: the index of the current line
 *
 * Return: Nothing
 */
void _stack(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;

	montyflag = 0;
	statusfunc = 1;
}
