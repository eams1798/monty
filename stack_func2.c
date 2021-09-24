#include "monty.h"

/**
 * _pint - prints the value at the top of the stack, followed by a new line
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _pint(stack_t **stack, unsigned int line)
{
	int top;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		statusfunc = 0;
		return;
	}
	top = (*stack)->n;
	printf("%d\n", top);
	statusfunc = 1;
}

/**
 * _pop - removes the top element of the stack
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _pop(stack_t **stack, unsigned int line)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		statusfunc = 0;
		return;
	}
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

/**
 * _add - adds the top two elements of the stack, stores the result in the
 * second element and pops the first element of the stack
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

/**
 * _sub - subtracts the second element of the stack with the first element,
 * stores the result in the second element and pops the first element
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

/**
 * _mul - multiplies the top two elements of the stack, stores the result in
 * the second element and pops the first element of the stack
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}
