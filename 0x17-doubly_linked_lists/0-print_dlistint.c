#include "lists.h"

/**
 * print_dlistint - prints all the elements of
 * a dlistint_t list.
 * @h: pointer to the first node of the list.
 * Return: number of nodes
*/
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp;
	size_t count = 0;

	if (h == NULL)
	{
		return (count);
	}
	temp = h;
	/* to be sure we are at the first node */
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		count++;
		temp = temp->next;
	}
	return (count);
}
