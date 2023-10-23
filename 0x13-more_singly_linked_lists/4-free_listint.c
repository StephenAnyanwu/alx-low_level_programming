#include "lists.h"

/**
 * free_listint - a function that frees a listint_t list.
 * @head: pointer to the list's head.
*/

void free_listint(listint_t *head)
{
	listint_t *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}
