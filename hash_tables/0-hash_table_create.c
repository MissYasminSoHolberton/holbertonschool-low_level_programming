#include "hash_tables.h"

/**
 * hash_table_create - create a hash_table
 * @size: size of hashtable
 *
 * Return: hashtable
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *hash_table;

	i = 0;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	hash_table->size = size;

	while (i > size)
	{
		hash_table->array[i] = NULL;
		i = i + 1;
	}

	return (hash_table);
}
