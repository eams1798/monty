#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: a given stack
 * @line: the index of the current line
 *
 * The pushed element will be obtained from the global variable "arguments",
 * which gets the value of all given arguments of the current line
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line)
{
	int data;

	if (arguments[1] == NULL || isnumber(arguments[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		statusfunc = 0;
		return;
	}
	data = atoi(arguments[1]);
	/**
	 * montyflag set to 0 means the data is set to a stack (LIFO)
	 * if the data is set to a stack, "_push" pushes a new element
	 * at the beginning of the data
	 */
	if (montyflag == 0)
		add_dnodeint(stack, data);
	/**
	 * montyflag set to 1 means the data is set to a queue (FIFO)
	 * if the data is set to a queue, "_push" pushes a new element
	 * at the end of the data
	 */
	if (montyflag == 1)
		add_dnodeint_end(stack, data);
	statusfunc = 1;
}

/**
 * _pall - prints all the values on the stack, starting from the top of
 * the stack
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If the stack is empty, "_pall" doesn’t print anything
 * Return: Nothing
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *ptr;
	(void)line;

	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
		printf("%d\n", ptr->n);
	statusfunc = 1;
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _swap(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line);
		statusfunc = 0;
		return;
	}
	swap_stack(stack);
	statusfunc = 1;
}

/**
 * _nop - doesn’t do anything
 * @stack: a given stack
 * @line: the index of the current line
 *
 * Return: Nothing
 */
void _nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	statusfunc = 1;
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _pchar(stack_t **stack, unsigned int line)
{
	int top;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		statusfunc = 0;
		return;
	}
	top = (*stack)->n;
	if (top < 32 || top > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line);
		statusfunc = 0;
		return;
	}
	printf("%c\n", top);
	statusfunc = 1;
}
