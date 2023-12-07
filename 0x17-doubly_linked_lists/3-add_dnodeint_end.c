#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlisint_t
 * list.
 * @head: a pointer to a pointer to the first node of the list.
 * @n: integer to be added.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	while ((*head)->next != NULL)
		*head = (*head)->next;
	(*head)->next = new_node;
	new_node->prev = *head;
	*head = temp;
	return (new_node);
}
