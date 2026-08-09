#include "lists.h"

/**
 * add_dnodeint - adding a node to the list
 * @h: head of list
 *
 * Return: address of the new element NULL if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;

	return (new);
}
