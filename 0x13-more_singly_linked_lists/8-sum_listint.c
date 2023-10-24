#include "lists.h"

/**
 * sum_listint - a function that sums all the data (n) of
 * a listint_t linked list.
 * @head: a pointer to the head of the list.
 * Return: the sum of all data (n), 0 if list is empty;
*/

int sum_listint(listint_t *head)
{
	int sum;
	listint_t *ptr = head;

	if (head == NULL)
		return (0);
	sum = 0;
	while (ptr != NULL)
	{
		sum += ptr->n;
		ptr = ptr->next;
	}
	return (sum);
}
