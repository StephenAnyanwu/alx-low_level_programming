#include "lists.h"

/**
 * listint_len - a function that calcultes the number
 * of elementsi(nodes) in a linked listint_t list.
 * @h: pointer to list's head.
 * Return: number of listint_t list elements (nodes).
*/

size_t listint_len(const listint_t *h)
{
	size_t num_nodes = 0;

	if (h == NULL)
		return (num_nodes);
	while (h != NULL)
	{
		num_nodes++;
		h = h->next;
	}
	return (num_nodes);
}
