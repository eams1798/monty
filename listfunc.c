#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: the head of a list
 * @n: the piece of data of the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t)), *ptr = *head;

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	if (ptr != NULL)
	{
		new->next = ptr;
		ptr->prev = new;
	}
	else
		new->next = NULL;
	*head = new;
	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: the head of a list
 * @n: the piece of data of the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t)), *ptr;

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	new->prev = ptr;
	ptr->next = new;
	return (new);
}
