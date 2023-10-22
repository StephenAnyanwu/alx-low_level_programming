#include "lists.h"
#include <stdio.h>

/**
 * list_len - a function that calculates the number of
 * elements (nodes) in a linked list_t list.
 * @h: list to be be calculated.
 * Return: the number of elements.
*/

size_t list_len(const list_t *h)
{
	size_t num_nodes = 0;
	const list_t *ptr;

	if (h == NULL)
		return (0);
	ptr = h;
	while (ptr != NULL)
	{
		num_nodes++;
		ptr = ptr->next;
	}
	return (num_nodes);
}
