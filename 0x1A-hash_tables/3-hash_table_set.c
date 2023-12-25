#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/* Steps involved in adding an element in a hash table using */
/* hash_table-set function. */
/* >> Create the item based on the { key: value } pair. */
/* >> Compute the index based on the hash function. */
/* >> Check if the index is already occupied or not, by comparing the key.*/
/*	>> If it is not occupied, you can directly insert it into index. */
/*	>> Otherwise, it is a collision, and you will need to handle it using */
/*	   using chaining method (closed addressing): */
/*		>> Updating the item if key already exist in the linked list */
/*		>> adding the new item (node) at the beginning of the linked */
/*		list if key does not exist*/


/**
 * create_item - creates an item (a node).
 * @key: key of the item.
 * @value: value of the item.
 * Return: a pointer to the item created.
*/
hash_node_t *create_item(const char *key, const char *value)
{
	/* a pointer to a hash_table_t item */
	hash_node_t *item = malloc(sizeof(hash_node_t));
	/* allocates memory to the item key */
	item->key = malloc(strlen(key) + 1);
	/* allocates memory to the item value */
	item->value = malloc(strlen(value) + 1);
	if (item == NULL || item->key == NULL || item->value == NULL)
		return (NULL);
	item->next = NULL;
	strcpy(item->key, key);
	strcpy(item->value, value);
	return (item);
}

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: the hash table.
 * @key: key of item (can not be an empty string).
 * @value: value of item (can be an empty string). Note that
 * value must be duplicated.
 * Return: 1 if it succeeded, 0 otherwise.
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *item, *item_loc;
	char *value_dup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_dup = strdup(value); /* duplicates value */
	if (value_dup == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size); /* hash key */
	item = create_item(key, value_dup);
	if (item != NULL)
	{
		if (ht->array[idx] == NULL) /* no collision */
			ht->array[idx] = item; /* insert directly */
		else /* collision, add at the beginning of list */
		{
			item_loc = ht->array[idx];
			while (ht->array[idx] != NULL)
			{/* checks if item's key already exist in the list */
				if (strcmp(ht->array[idx]->key, key) == 0)
				{/* update item if key already exist in the list */
					strcpy(ht->array[idx]->value, value_dup);
					free(value_dup);
					value_dup = NULL;
					ht->array[idx] = item_loc;
					return (1);
				}
				ht->array[idx] = ht->array[idx]->next;
			}
			ht->array[idx] = item_loc;
			ht->array[idx] = item;
			ht->array[idx]->next = item_loc;
		}
		free(value_dup);
		value_dup = NULL;
		return (1);
	}
	return (0);
}
