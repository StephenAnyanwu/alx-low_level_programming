#include "lists.h"
#include <stdio.h>

/**
 * print_listint - a function that prints all
 * the elements of a listint_t list.
 * @h: head pointer of the list.
 * Return: numher of nodes.
*/

size_t print_listint(const listint_t *h)
{
	size_t num_nodes = 0;
	const listint_t *ptr;

	if (h == NULL)
		return (num_nodes);
	ptr = h;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		num_nodes++;
		ptr = ptr->next;
	}
	return (num_nodes);
}
