#include "lists.h"

/**
 * add_dnodeint_end - freeing list
 * @head: head of list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
