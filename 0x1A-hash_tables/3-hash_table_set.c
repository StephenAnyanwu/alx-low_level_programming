#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/* Steps involved in adding an element in a hash table using */
/* hash_table-set function. */
/* >> Create the item based on the { key: value } pair. */
/* >> Compute the index based on the hash function. */
/* >> Check if the index is already occupied or not, by comparing the key.*/
/*	>> If it is not occupied, you can directly insert it into index. */
/*	>> Otherwise, it is a collision, and you will need to handle it. */


/**
 * create_item - creates an item (a node).
 * @key: key
 * @value: value
 * Return: a pointer to the item created.
*/
hash_node_t *create_item(const char *key, const char *value)
{
	/* a pointer to a new hash_table_t item */
	hash_node_t *item = malloc(sizeof(hash_node_t));

	item->key = malloc(strlen(key) + 1);
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
 * @key: key.
 * @value: value.
 * Return: 1 if it succeeded, 0 otherwise.
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx = key_index((const unsigned char *)key, ht->size);
	hash_node_t *item = create_item(key, value);
	hash_node_t *item_loc = ht->array[idx];

	/* location to add item in array is empty */
	if (item_loc == NULL)
	{
		ht->array[idx] = item; /* insert directly */
		return (1);
	}
	/* scenerio when there is a collision add the item */
	/* (new node) at the beginning of the list */
	else
	{
		ht->array[idx] = item;
		ht->array[idx]->next = item_loc;
		return (1);
	}
	return (0);
}
