#include "monty.h"

/**
 * _div - divides the second element of the stack with the first element,
 * stores the result in the second element and pops the first element
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n /= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

/**
 * _pstr - prints a string starting at the top of the stack, followed by a
 * new line
 * @stack: a given stack
 * @line: the index of the current line
 *
 * The printing stops if there isn't a printable ascii character
 * Return: Nothing
 */
void _pstr(stack_t **stack, unsigned int line)
{
	int c;
	stack_t *ptr = *stack;

	(void)line;
	while (ptr != NULL)
	{
		c = ptr->n;
		if (c < 32 || c > 126)
			break;
		putchar(c);
		ptr = ptr->next;
	}
	putchar('\n');
	statusfunc = 1;
}

/**
 * _mod - stores the rest of the division of the second element of the stack
 * with the first element and pops the first element
 * @stack: a given stack
 * @line: the index of the current line
 *
 * If there was an error, the function sets the global variable "statusfunc"
 * to 0, but sets it to 1 if there wasn't any errors
 * Return: Nothing
 */
void _mod(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

/**
 * _rotr - rotates the stack to the bottom
 * The last element of the stack becomes the top element of the stack
 * @stack: a given stack
 * @line: the index of the current line
 *
 * The function never fails
 * Return: Nothing
 */
void _rotr(stack_t **stack, unsigned int line)
{
	stack_t *head, *last;

	(void)line;
	if (dlistint_len((*stack)) < 2)
	{
		statusfunc = 1;
		return;
	}
	head = *stack;
	last = head;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
	*stack = last;
	statusfunc = 1;
}

/**
 * _rotl - rotates the stack to the top
 * The top element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * @stack: a given stack
 * @line: the index of the current line
 *
 * The function never fails
 * Return: Nothing
 */
void _rotl(stack_t **stack, unsigned int line)
{
	stack_t *head, *last;

	(void)line;
	if (dlistint_len((*stack)) < 2)
	{
		statusfunc = 1;
		return;
	}
	head = *stack;
	last = head;
	while (last->next != NULL)
		last = last->next;
	*stack = head->next;
	head->next->prev = NULL;
	head->next = NULL;
	head->prev = last;
	last->next = head;
	statusfunc = 1;
}
