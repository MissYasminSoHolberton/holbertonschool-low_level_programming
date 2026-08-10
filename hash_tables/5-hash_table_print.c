#include "hash_tables.h"

/**
 * hash_table_print - print hastable
 * @ht: hashtable to edit
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	char *delimeter;

	if (ht == NULL)
		return;

	printf("{");
	i = 0;
	delimeter = "";
	while (i < ht->size)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			printf("%s", delimeter);
			printf("'%s': ", node->key);
			printf("'%s'", node->value);
			node = node->next;
			delimeter = ", ";
		}
		i = i + 1;
	}
	printf("}\n");
}
