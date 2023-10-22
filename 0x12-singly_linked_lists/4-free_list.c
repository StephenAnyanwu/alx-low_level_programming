#include "lists.h"
#include <stdlib.h>

/**
 * free_list - a function that frees list_t list.
 * @head: pointer to the head of list_t list/
*/

void free_list(list_t *head)
{
	list_t *ptr;

	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		ptr = head->next;
		free(head->str);
		free(head);
		head = ptr;
	}
	free(head->str);
	free(head);
}
