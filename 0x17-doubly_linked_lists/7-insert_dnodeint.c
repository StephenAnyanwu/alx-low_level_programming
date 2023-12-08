#include "lists.h"

/**
 * dlist_len - finds the number of elements in a dlistint_t
 * list.
 * @h: pointer to the first node of the list.
 * Return: number of element.
*/
unsigned int dlist_len(dlistint_t *h)
{
	dlistint_t *temp;
	unsigned int count = 0;

	if (h == NULL)
		return (count);
	temp = h;
	/* be be sure that we are at the first node */
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: a pointer to a pointer to the first node of a list.
 * @idx:  the index of the list where the new node should
 * be added. Index starts at 0.
 * @n: integer value of the new node.
 * Return: the address of the new node, or NULL if it failed.
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t)), *temp = *h;
	unsigned int list_len = dlist_len(temp), ch = 0;

	if (new_node == NULL || idx > list_len)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (list_len == 0)
	{
		*h = new_node;
		return (new_node);
	}
	if (idx == 0)
	{
		new_node->next = *h;
		(*h)->prev = new_node;
	}
	if (idx == list_len)
	{
		while ((*h)->next != NULL)
			*h = (*h)->next;
		(*h)->next = new_node;
		new_node->prev = *h;
	}
	if (idx > 0 && idx < list_len)
	{
		while (ch < (idx - 1))
		{
			*h = (*h)->next;
			ch++;
		}
		new_node->next = (*h)->next;
		(*h)->next->prev = new_node;
		(*h)->next = new_node;
		new_node->prev = *h;
	}
	*h = temp;
	return (new_node);
}
