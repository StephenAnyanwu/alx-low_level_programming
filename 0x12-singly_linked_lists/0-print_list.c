#include <stdio.h>
#include "lists.h"

/**
 * print_list - a function that prints all the elements of
 * list_t list.
 * @h: list_t list that its elements will be printed.
 * Return: the number of nodes.
*/

size_t print_list(const list_t *h)
{
	size_t count = 0;
	const list_t *ptr;

	if (h == NULL)
		return (0);
	ptr = h;
	while (ptr != NULL)
	{
		if (ptr->str != NULL)
			printf("[%d] %s\n", ptr->len, ptr->str);
		else
			printf("[0] (nil)\n");
		count++;
		ptr = ptr->next;
	}
	return (count);
}
