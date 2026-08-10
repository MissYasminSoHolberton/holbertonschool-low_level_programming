#include "lists.h"

/**
 * get_dnodeint_at_index - get the node at index
 * @head: head of list
 * @index: index of the node
 *
 * Return: node if found, NULL not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	i = 0;

	if (head == NULL)
	{
		return (NULL);
	}

	node = head;

	while (node != NULL && i < index)
	{
		node = node->next;
		i = i + 1;
	}

	if (index != i)
	{
		return (NULL);
	}

	return (node);
}
