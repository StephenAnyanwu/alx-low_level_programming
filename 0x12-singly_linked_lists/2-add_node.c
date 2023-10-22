#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - a function that adds a new node.
 * at the beginning of a list_t list.
 * @head: head of the liked list.
 * @str: string of the new node.
 * Return: address of the new element, or NULL if it failed.
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_head;

	new_head = malloc(sizeof(list_t));
	if (new_head == NULL)
		return (NULL);
	new_head->str = strdup(str);
	new_head->len = strlen(str);
	new_head->next = *head;
	*head = new_head;
	return (*head);
}
