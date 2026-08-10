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

	if (ht == NULL)
	{
		return (0);
	}

	index = key_index((unsigned char *)key, ht->size);

	node = ht->array[index];

	if (node == NULL)
	{
		ht->array[index] = ht_pair(key, value);
		return (1);
	}

	ht_pair(key, value)->next = node;

	return (1);
}
