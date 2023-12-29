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
	hash_table_t *table = (hash_table_t *)malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);
	table->size = size;
	/* creates an array that stores hash_node_t pointers*/
	table->array = (hash_node_t **)calloc(table->size, sizeof(hash_node_t *));
	if (table->array == NULL)
		return (NULL);
	/* initializes the array with NULL */
	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
	return (table);
}
