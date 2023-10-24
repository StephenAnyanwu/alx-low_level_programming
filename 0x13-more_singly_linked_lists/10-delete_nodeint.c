#include "lists.h"

/**
 * delete_nodeint_at_index - a function that deletes the node
 * at index index of a listint_t linked list.
 * @head: a pointer to a pointer to the list's head.
 * @index: the index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *del_node, *ptr;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		del_node = *head;
		*head = (*head)->next;
		free(del_node);
		del_node = NULL;
		return (1);
	}
	ptr = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (ptr->next == NULL)
			return (-1);
		ptr = ptr->next;
	}
	del_node = ptr->next;
	ptr->next = del_node->next;
	free(del_node);
	del_node = NULL;
	return (1);
}

