#include "lists.h"

/**
 * dlistint_len - finds the number of elements in a dlistint_t
 * list.
 * @h: pointer to the first node of the list.
 * Return: number of element.
*/
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *temp;
	size_t count = 0;

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
