#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - a function that creates a hash table.
 * @size: size of the hash table (array).
 * Return: a pointer to the newly created hash table or NULL
 * if something went wrong.
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	/* creates a new hash table */
	hash_table_t *table = malloc(sizeof(hash_table_t));

	if (table == NULL)
		return (NULL);
	table->size = size;
	table->array = calloc(table->size, sizeof(hash_node_t *));
	if (table->array == NULL)
		return (NULL);
	/* initializes the array with NULL */
	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
	return (table);
}
