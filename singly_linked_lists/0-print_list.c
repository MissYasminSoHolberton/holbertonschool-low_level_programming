#include <stddef.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints contents of list
 * @h: list to print
 *
 * Return: number of nodes in list
 */
size_t print_list(const list_t *h)
{
	int count;
	char *element;

	count = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			element = "(nil)";
		}
		else
		{
			element = h->str;
		}
		printf("[%d] %s\n", h->len, element);
		count = count + 1;
		h = h->next;
	}

	return (count);
}
