#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: the key you are looking for. Note must not be an empty
 * string or NULL.
 * Return: the value associated with the element, or NULL if key
 * couldn’t be found.
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *item_loc;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	item_loc = ht->array[idx];

	if (item_loc != NULL)
	{

		while (item_loc->next != NULL)
		{
			if (strcmp(item_loc->key, key) == 0)
				return (item_loc->value);
			item_loc = item_loc->next;
		}
		if (strcmp(item_loc->key, key) == 0)
			return (item_loc->value);
	}
	return (NULL);
}
