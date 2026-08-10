#include "lists.h"

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: head of list
 * @index: index to insert the node
 *
 * Return: 1 if success, -1 otherwise
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr;
	unsigned int i;

	i = 0;

	if (head == NULL)
		return (-1);
	if (*head == NULL)
	{
		return (-1);
	}
	curr = *head;
	while (curr->next != NULL && i < index)
	{
		curr = curr->next;
		i = i + 1;
	}
	if (i != index)
	{
		return (-1);
	}

	if (curr->prev != NULL)
	{
		curr->prev->next = curr->next;
	}
	else
	{
		*head = curr->next;
	}

	if (curr->next != NULL)
	{
		curr->next->prev = curr->prev;
	}
	free(curr);

	return (1);
}
