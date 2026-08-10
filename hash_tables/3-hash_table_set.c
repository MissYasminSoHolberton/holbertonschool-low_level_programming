#include "hash_tables.h"

/**
 * ht_pair - creates a node
 * @key: key
 * @value: value
 *
 * Return: created pair
 */
hash_node_t *ht_pair(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	node->key = malloc(strlen(key) + 1);
	node->value = malloc(strlen(value) + 1);

	strcpy(node->key, key);
	strcpy(node->value, value);

	node->next = NULL;

	return (node);
}

/**
 * hash_table_set - adds element to hashtable
 * @key: key
 * @value: value to be added
 * @ht: hashtable to edit
 *
 * Return: 1 succeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	int index;
	hash_node_t *node;
	hash_node_t *new;
	char *new_value;

	if (ht == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = malloc(strlen(value) + 1);
			if (new_value == NULL)
				return (0);

			strcpy(new_value, value);

			free(node->value);
			node->value = new_value;

			return (1);
		}
		node = node->next;
	}

	new = ht_pair(key, value);

	if (new == NULL)
	{
		return (1);
	}
	new->next = ht->array[index];
	ht->array[index] = new;

	return (1);
}
