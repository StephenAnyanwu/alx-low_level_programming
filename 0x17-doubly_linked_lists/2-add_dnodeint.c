#include "lists.h"

/**
 * add_dnodeint - addsa new node at the beginning of
 * a dlistint_t list.
 * @head: a pinter to a pointer to the first node.
 * @n: integer to be added.
 * Return: the address (pointer) to the new element, or
 * NULL if it failed.
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
	return (new_node);
}
