#include "lists.h"

/**
 * insert_dnodeint_at_index - insert a node in index
 * @h: head of list
 * @idx: index to insert the node
 * @n: value of elemeent
 *
 * Return: list with inserted node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new;
	dlistint_t *curr;
	unsigned int i;

	i = 0;

	if (h == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}
	if (*h == NULL)
	{
		free(new);
		return (NULL);
	}
	new->n = n;
	curr = *h;
	while (curr->next != NULL && i < idx - 1)
	{
		curr = curr->next;
		i = i + 1;
	}
	if (i != idx - 1)
	{
		free(new);
		return (NULL);
	}
	new->next = curr->next;
	if (curr->next != NULL)
	{
		curr->next->prev = new;
	}
	curr->next = new;
	new->prev = curr;
	return (new);
}
