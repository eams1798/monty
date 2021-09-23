#include "monty.h"

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
	add_dnodeint(stack, data);
	statusfunc = 1;
}

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
		printf("%d\n", ptr->n);
	statusfunc = 1;
}

void _swap(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	statusfunc = 1;
}

void _pchar(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _add(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _sub(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _mul(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _div(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _pstr(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _mod(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _rotl(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _rotr(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
