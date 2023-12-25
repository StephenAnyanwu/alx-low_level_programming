#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print -  a function that prints a hash table.
 * @ht: a pointer to the hash table to be printed.
 * It prints the key/value in the order that they appear in
 * the array of hash table.
 * Order: array, list
 * If hash table is NULL, it prints nothing.
*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *item;
	unsigned long int i;
	int check = 0;

	if (ht == NULL)
	{
		printf("{}\n");
		return;
	}
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (i > 0 && check)
			{
				printf(", ");
				check = 0;
			}
			item = ht->array[i];
			if (item->next != NULL)
			{
				while (item->next != NULL)
				{
					printf("'%s': '%s', ", item->key, item->value);
					item = item->next;
				}
				printf("'%s': '%s'", item->key, item->value);
			}
			else
				printf("'%s': '%s'", item->key, item->value);
			check = 1;
		}
	}
	printf("}\n");
}
