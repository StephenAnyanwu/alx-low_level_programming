#include "hash_tables.h"
#include <stdlib.h>

/* Deleting a hash table using has_table_delete funstion */
/* >> Iterating through the array in the hash table */
/*	>> In every location (if it's not NULL) in the array, */
/*	   if no collision is noticed, delete the item in that */
/*	   location by freeing its key/value pairs and freeing the */
/*	   item afterwards. If collision is noticed, iterate through */
/*	   the items (nodes), delete their respective key/value pair and */
/*	   delete the items afterwards. */
/* >> Delete the array of the hash table */
/* >> Delete the hash table. */

/**
 * delete_item - a function that deletes an item in a hash table.
 * @item: item of the hash table to delete.
*/
void delete_item(hash_node_t *item)
{
	free(item->key);
	item->key = NULL;
	free(item->value);
	item->value = NULL;
	free(item);
	item = NULL;
}

/**
 * hash_table_delete - a function that deletes a hash table.
 * @ht: hash table to delete.
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			while (ht->array[i]->next != NULL)
			{
				temp = ht->array[i]->next;
				delete_item(ht->array[i]);
				ht->array[i] = temp;
			}
			delete_item(ht->array[i]);
		}
	}
	free(ht->array);
	ht->array = NULL;
	free(ht);
	ht = NULL;
}
