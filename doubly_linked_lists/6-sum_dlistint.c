#include "lists.h"

/**
 * sum_dlistint - get sum of the list
 * @head: head of list
 *
 * Return: sum of the elements in list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	while (head != NULL)
	{
		sum = head->n + sum;
		head = head->next;
	}
	return (sum);
}
