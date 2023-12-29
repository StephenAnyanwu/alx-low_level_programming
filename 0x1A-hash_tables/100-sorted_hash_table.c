#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* We are to impliment a hash table that when printing the items */
/* added to it, the items will be sorted and printed in the order */
/* of the ASCII value of their keys not in the order they they were added. */
/* In PHP, the items are sorted by their keys in the order they were added. */

/**
 * shash_table_create - a function that creates a sorted hash table.
 * @size: size of the hash table array.
 * Return: a pointer to the newly created hash table or NULL
 * if something went wrong.
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *table;

	/* creates a new hash table */
	table = (shash_table_t *)malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);
	table->size = size;
	/* creates an array that stores shash_node_t pointers */
	table->array = (shash_node_t **)calloc(table->size, sizeof(shash_node_t *));
	if (table->array == NULL)
		return (NULL);
	/* initializes the array with NULL */
	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
	table->shead = NULL; /* initialized head of the sorted list */
	table->stail = NULL; /* initialized tail of the sorted list */
	return (table);
}

/**
 * create_item - creates an item (a node).
 * @key: key of the item.
 * @value: value of the item.
 * Return: a pointer to the item created.
*/
shash_node_t *create_item(const char *key, const char *value)
{
	/* a pointer to a shash_table_t item */
	shash_node_t *item = (shash_node_t *)malloc(sizeof(shash_node_t));

	if (item == NULL)
		return (NULL);
	/* allocates memory to the item key */
	item->key = malloc(strlen(key) + 1);
	if (item->key == NULL)
		return (NULL);
	/* allocates memory to the item value */
	item->value = malloc(strlen(value) + 1);
	if (item->value == NULL)
		return (NULL);
	strcpy(item->key, key);
	strcpy(item->value, value);
	item->next = NULL;
	item->snext = NULL;
	item->sprev = NULL;
	return (item);
}

/**
* add_to_slist - adds a node at the tail of the sorted
* doubly linked list.
* the sorted doubly linked list is created based on the order
* in which the items are
* added to the hashtable.
* @ht: hash table containing the head and tail pointers of the
* sorted linked list.
* @n: node to be added to the sorted list.
* @k: key of the node.
* @v: value of the node
*/
void add_to_slist(shash_table_t *ht, shash_node_t *n, const char *k, char *v)
{
	shash_node_t *temp = ht->shead;

	if (ht->shead == NULL && ht->stail == NULL) /* if sorted list is empty */
	{
		ht->shead = n;
		ht->stail = n;
		return;
	}
	if (ht->shead == ht->stail) /* if sorted list has one node */
	{	/* if the key of the node equals new key, update the node value */
		if (strcmp(ht->shead->key, k) == 0)
		{
			strcpy(ht->shead->value, v);
			return;
		}
		/* if not, add to the end of list */
		ht->stail = n;
		ht->stail->sprev = ht->shead;
		ht->shead->snext = ht->stail;
		return;
	}
	if (ht->shead->snext) /* if sorted list is more than one node */
	{
		while (ht->shead != NULL)/* traverse the sorted list */
		{
			/* if key already exist in the sorted list, update */
			/* the value of that node with equal key */
			if (strcmp(ht->shead->key, k) == 0)
			{
				strcpy(ht->shead->value, v);
				return;
			}
			ht->shead = ht->shead->snext;
		}
		ht->shead = temp;
		ht->stail->snext = n; /* add node at the end of sorted list */
		n->sprev = ht->stail;
		ht->stail = n;
		return;
	}
}

/**
 * shash_table_set - adds an element to the hash table.
 * @ht: the hash table.
 * @key: key of item (can not be an empty string).
 * @value: valueof item (can be an empty string). Note that
 * value must be duplicated.
 * Return: 1 if it succeeded, 0 otherwise.
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	shash_node_t *item, *item_loc;
	char *value_dup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_dup = strdup(value); /* duplicates value */
	if (value_dup == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size); /*hashed key */
	item = create_item(key, value_dup); /* creates item */
	if (item != NULL)
	{
		add_to_slist(ht, item, key, value_dup); /* adds item to sorted linked list */
		if (ht->array[idx] == NULL) /* if no collision, insert directly */
			ht->array[idx] = item;
		else /* collision, add the the beginning of th list */
		{
			item_loc = ht->array[idx]; /* location to place item in array */
			while (ht->array[idx] != NULL) /* traverse the list */
			{/* checks if item's key already exist in the list */
				if (strcmp(ht->array[idx]->key, key) == 0)
				{ /* updates item's value */
					strcpy(ht->array[idx]->value, value_dup);
					free(value_dup);
					value_dup = NULL;
					ht->array[idx] = item_loc;
					return (1);
				}
				ht->array[idx] = ht->array[idx]->snext;
			}
			ht->array[idx] = item_loc;
			ht->array[idx] = item; /* add item at the beginning of the list */
			ht->array[idx]->next = item_loc;
		}
		free(value_dup);
		value_dup = NULL;
		return (1);
	}
	return (0);
}

/**
 * linked_list_len - calculates the length of a linked list.
 * in a hash table.
 * @ht: the hash table.
 * Return: length of of linked list.
 */
unsigned long int linked_list_len(const shash_table_t *ht)
{
	unsigned long int len = 0;
	shash_node_t *ptr;

	/* if list is empty */
	if (ht->shead == NULL)
		return (0);
	ptr = ht->shead;
	/*traverse the list and count the number of nodes */
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->snext;
	}
	return (len);
}

/**
 * shash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to retrieve value from.
 * @key: the key you are looking for. Note key must not be an empty
 * string or NULL.
 * Return: the value associated with the item, or NULL if key
 * couldn’t be found.
 * Note: chaining method (closed addressing) is used in collision.
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *item_loc;

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

/**
 * selection_sort - sorts a hash table by the first character of
 * its items keys.
 * @ht: the hash table.
 */
void selection_sort(const shash_table_t *ht)
{
	shash_node_t *ptr1, *ptr2;
	char *temp_key, *temp_value;

	for (ptr1 = ht->shead; ptr1->snext != NULL; ptr1 = ptr1->snext)
		for (ptr2 = ptr1->snext; ptr2 != NULL; ptr2 = ptr2->snext)
			if (ptr1->key[0] > ptr2->key[0])
			{
				temp_key = ptr1->key;
				temp_value = ptr1->value;
				ptr1->key = ptr2->key;
				ptr1->value = ptr2->value;
				ptr2->key = temp_key;
				ptr2->value = temp_value;
			}
}

/**
 * shash_table_print - prints a hash table key/value pair using
 * sorted list by ascii value.
 * @ht: the hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL || ht->shead == NULL)
		return;
	selection_sort(ht);
	node = ht->shead;
	while (node->snext != NULL)
	{
		printf("'%s: '%s', ", node->key, node->value);
		node = node->snext;
	}
	printf("'%s: '%s'\n", node->key, node->value);
}

/**
 * shash_table_print_rev - prints the hash table key/pair in
 * reversed order usinf the sorted linked list.
 * @ht: the hass table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL || ht->shead == NULL)
		return;
	node = ht->stail;
	while (node->sprev != NULL)
	{
		printf("'%s: '%s', ", node->key, node->value);
		node = node->sprev;
	}
	printf("'%s: '%s'\n", node->key, node->value);
}

/**
 * shash_table_delete - deletes shash_table_t hash table.
 * @ht: the has table.
*/
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *temp;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			while (ht->array[i] != NULL)
			{
				temp = ht->array[i]->next;
				free(ht->array[i]->value);
				free(ht->array[i]->key);
				ht->array[i]->value = NULL;
				ht->array[i]->key = NULL;
				ht->array[i] = temp;
			}
		}
	}
	free(ht->array);
	ht->array = NULL;
	while (ht->shead != NULL)
	{
		temp = ht->shead->snext;
		free(ht->shead->value);
		free(ht->shead->key);
		ht->shead->value = NULL;
		ht->shead->key = NULL;
		ht->shead = temp;
	}
	free(ht);
	ht = NULL;
}
