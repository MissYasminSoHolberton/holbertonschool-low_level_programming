#include "hash_tables.h"

/**
 * hash_table_create - create a hash_table
 * @size - size of hashtable
 *
 * Return: hashtable
 */
 hash_table_t *hash_table_create(unsigned long int size)
 {
	hash_table_t *hash_table;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->array = malloc(sizeof(hash_node_t) * size);
	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	return (hash_table);
 }
