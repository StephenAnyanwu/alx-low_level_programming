#include "lists.h"

/**
 * reverse_listint - a function that reverses a listint_t linked list.
 * @head: a pointer to pointer to the list's head.
 * Return: a pointer to the first node of the reversed list.
*/

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);
	/* if only one node */
	if ((*head)->next == NULL)
		return (*head);
	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}
