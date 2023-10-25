#include "lists.h"

/**
 * _relo - relocates memory for an array of pointers to the
 * nodes in a linked list.
 * @list: the old list to append.
 * @size: size of the old list (always one more than the old list).
 * @new: new node to append to the list.
*/

listint_t **_relo(listint_t **list, size_t size, listint_t *new)
{
	listint_t **newlist;
	size_t i;

	newlist = malloc(sizeof(listint_t *) * size);
	if (newlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
	{
		newlist[i] = list[i];
	}
	newlist[i] = new;
	free(list);
	return (newlist);
}

/**
 * free_listint_safe -  a function that free a listint_t linked list.
 * @head: pointer to the list's head.
 * Return: size of the list that was freed.
*/

size_t free_listint_safe(listint_t **head)
{
	size_t i, n = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (n);
	while (*head != NULL)
	{
		for (i = 0; i < n; i++)
		{
			if (*head == list[i])
			{
				*head = NULL;
				free(list);
				return (n);
			}
		}
		n++;
		list = _relo(list, n, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (n);
}
