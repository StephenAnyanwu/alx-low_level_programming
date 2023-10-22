#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_node_end - a function that adds a new node
 * at the end of a list_t list.
 * @head: head of the list_t list.
 * @str: string of the new node.
 * Return:the address of the new element, or NULL if it failed.
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *ptr;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->str = strdup(str);
	new_node->len = strlen(str);
	ptr = *head;
	if (ptr == NULL)
		*head = new_node;
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
	return (*head);
}
