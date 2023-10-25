#include "lists.h"

/**
 * relo - relocate memmory for array of pointer to the nodes
 * in linked list.
 * @list: the old list to append.
 * @size: size of the new list (one more than the old list).
 * @new: new node to be added to the list.
 * Return: pointer to the new list.
*/
const listint_t **relo(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newlist;
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
 * print_listint_safe -  a function that prints a listint_t linked list.
 * @head: a pointer to the list's head.
 * Return:the number of nodes in the list.
 * If the function fails, exit the program with status 98.
*/

size_t print_listint_safe(const listint_t *head)
{
	size_t i, n = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (i = 0; i < n; i++)
		{
			if (head == list[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (n);
			}
		}
		n++;
		list = relo(list, n, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (n);
}
