#include "lists.h"

/**
 * add_dnodeint_end - adding a node to the end of the list
 * @head: head of list
 * @n: element to add
 *
 * Return: address of the new element NULL if failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *curr;

	if (head == NULL)
	{
		return (NULL);
	}

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	curr = *head;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = new;
	new->prev = curr;

	return (new);
}
