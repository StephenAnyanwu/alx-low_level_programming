#include "lists.h"

/**
 * pop_listint - a function that deletes the head
 * node of a listint_t linked list
 * @head: a pointer to a pointer to the list head.
 * Return: the head node’s data (n), 0 if linked list is empty.
*/
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	temp = *head;
	*head = temp->next;
	n = temp->n;
	free(temp);
	return (n);
}
