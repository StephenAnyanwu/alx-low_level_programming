#include "lists.h"

/**
 * dlist_len - finds the number of elements in a dlistint_t
 * list.
 * @h: pointer to the first node of the list.
 * Return: number of element.
*/
unsigned int dlist_len(dlistint_t *h)
{
	dlistint_t *temp;
	unsigned int count = 0;

	if (h == NULL)
		return (count);
	temp = h;
	/* to be sure that we are at the first node */
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

/**
 * add_inbetween - add aa node in between dlistint_t list.
 * @h: pointer to the first node of the list.
 * Return: first node pointer.
*/
dlistint_t *add_inbetween(dlistint_t *h)
{
	dlistint_t *ptr, *temp = h;

	ptr = h->next->next;
	free(h->next);
	h->next = NULL;
	h->next = ptr;
	ptr->prev = h;
	h = temp;
	return (h);
}


/**
 * delete_dnodeint_at_index - deletes the node at index index of
 * a dlistint_t linked list.
 * @head: a pointer to a pointer to the first node of the list.
 * @index:  the index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int list_len = dlist_len(temp), ch = 0;

	if (*head == NULL)
		return (-1);
	if ((index > 0 || !index)  && index < list_len)
	{
		if (index == 0)
		{
			if ((*head)->next == NULL)
			{
				free(*head);
				*head = NULL;
				return (1);
			}
			*head = (*head)->next;
			free((*head)->prev);
			(*head)->prev = NULL;
		}
		else if (index == list_len - 1)
		{
			while ((*head)->next != NULL)
				*head = (*head)->next;
			*head = (*head)->prev;
			free((*head)->next);
			(*head)->next = NULL;
			*head = temp;
		}
		else
		{
			while (ch < index - 1)
			{
				*head = (*head)->next;
				ch++;
			}
			*head = add_inbetween(*head);
		}
		return (1);
	}
	return (-1);
}
