#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: pointer to the first node of a list to be freed.
*/
void free_dlistint(dlistint_t *head)
{
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
	head = NULL;
}
