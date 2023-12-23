#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: the key you are looking for.
 * Return: the value associated with the element, or NULL if key
 * couldn’t be found.
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx = key_index((const unsigned char *)key, ht->size);
	hash_node_t *item_loc = ht->array[idx];

	if (item_loc != NULL)
	{
		if (strcmp(item_loc->key, key) == 0)
			return (item_loc->value);
		else
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
	}
	return (NULL);
}
