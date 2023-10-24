#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns
 * the nth node of a listint_t linked list.
 * @head: pointer to the list's head.
 * @index: the index of the node, starting at 0.
 * Return: nth node, NULL if list does not exist.
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *ptr;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	ptr = head;
	for (i = 0; i < index; i++)
		ptr = ptr->next;
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
