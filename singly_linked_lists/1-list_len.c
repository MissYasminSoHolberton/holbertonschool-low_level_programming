#include <stddef.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - length of list
 * @h: input list
 *
 * Return: number of elements in list
 */
size_t list_len(const list_t *h)
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
