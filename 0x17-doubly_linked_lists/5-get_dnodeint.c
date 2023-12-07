#include "lists.h"

/**
 * get_dnodeint_at_index - gets  nth node of a dlistint_t linked list.
 * @head: a pointer to the first node of the list.
 * @index: is the index of the node, starting from 0.
 * Return: the nth, or NULL if node does not exist.
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int ch = 0;
	dlistint_t *temp = head;

	if (head == NULL)
		return (NULL);
	while (temp->next != NULL)
	{
		if (ch == index)
			return (temp);
		temp = temp->next;
		ch++;
	}
	return (NULL);
}
