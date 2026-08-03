#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node_end - adding new node at the end
 * @head: head node
 * @str: string value
 *
 * Return: linked list
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *curr;
	int length;

	length = 0;

	if (head == NULL || str == NULL)
		return (NULL);

	new_node = malloc(sizeof(struct list_s));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	while (*str != '\0')
	{
		length = length + 1;
		str++;
	}

	new_node->len = length;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = new_node;
	return (new_node);
}
