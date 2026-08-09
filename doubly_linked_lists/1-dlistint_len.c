#include "lists.h"

/**
 * dlistint_len - returns length of list
 * @h: head of list
 *
 * Return: number of elements in list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int count;

	count = 0;

	while (h != NULL)
	{
		count = count + 1;
		h = h->next;
	}

	return (count);
}
