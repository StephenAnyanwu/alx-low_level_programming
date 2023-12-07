#include "lists.h"

/**
 * sum_dlistint - finds  sum of all the data (n)
 * of a dlistint_t linked list.
 * @head: first node of a list.
 * Return: sum value, or 0 if list is empty.
*/
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *temp = head;

	if (head == NULL)
		return (sum);
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	head = temp;
	temp = NULL;
	return (sum);
}
