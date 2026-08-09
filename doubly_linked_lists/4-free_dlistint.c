#include "lists.h"

/**
 * free_dlistint - freeing list
 * @head: head of list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		temp->prev = NULL;
		free(head);
		head = temp;
	}
}
