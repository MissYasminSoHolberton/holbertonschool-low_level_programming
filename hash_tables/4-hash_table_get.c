#include "hash_tables.h"

/**
 * hash_table_get - get value given a key
 * @key: key
 * @ht: hashtable to edit
 *
 * Return: value, null otherwise
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	char *result;
	int index;

	result = NULL;

	if (ht == NULL || key == NULL)
		return (result);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			result = node->value;
			return (result);
		}
		node = node->next;
	}

	return (NULL);
}
