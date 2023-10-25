#include "lists.h"

/**
 * find_listint_loop -  a function that finds the loop in a linked list.
 * @head: pointer to the head of the list.
 * Return: an  address of the node where the loop starts,
 * or NULL if there is no loop.
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ptr1, *ptr2;

	ptr1 = ptr2 = head;
	while (ptr1 != NULL && ptr2 != NULL && head->next != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;
		if (ptr1 == ptr2)
		{
			ptr1 = head;
			break;
		}

	}
	if (ptr1 == NULL || ptr2 == NULL || head == NULL)
		return (NULL);
	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return (ptr2);
}
