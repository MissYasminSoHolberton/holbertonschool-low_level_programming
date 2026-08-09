#include "lists.h"

/**
 * print_dlistint - prints all contents in list
 * @h: head of list
 *
 * Return: number of elements in list
 */
size_t print_dlistint(const dlistint_t *h)
{
	int count;

	count = 0;

	while (h != NULL)
	{
		printf("%d\n",h->n);
		count = count + 1;
		h = h->next;
	}

	return (count);
}
