#include "search_algos.h"

listint_t *take_step(listint_t *high, size_t size, size_t step);

/**
 * jump_list - Searches for a value in a sorted list of integers
 * using the Jump search algorithm.
 * @list: A pointer to the head of the list to search in.
 * @size: The number of nodes in list.
 * @value: The value to search for.
 * Return: A pointer to the first node where value is located, otherwise
 * NULL if value is not present in head or if head is NULL.
 * Description: Every time you compare a value in the list to the value
 * you are searching, you have to print this value.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step;
	listint_t *low, *high;

	if (list == NULL || size == 0)
		return (NULL);

	step = sqrt(size);
	low = high = list;
	while (1)
	{
		/* Increment high by taking size steps */
		high = take_step(high, size, step);
		printf("Value checked at index [%ld] = [%d]\n", high->index, high->n);
		/* Check if step is greater than the last index of list or if */
		/* element 'n' of high node (pointer) is greater than or equal to value */
		if (step > size - 1 || high->n >= value)
		{
			if (step > size - 1)
				step = size - 1;
			printf("Value found between indexes [%ld] and [%ld]\n", low->index, step);
			while (low->index <= high->index)
			{
				printf("Value checked at index [%ld] = [%d]\n", low->index, low->n);
				if (low->n == value)
					return (low);
				if (low == high && low->n != value)
					return (NULL);
				low = low->next;
			}
		}
		low = high;
		step += sqrt(size);
	}
}

/**
 * take_step - Moves a pointer to a new node in a singly linked list
 * while taking n steps.
 * @high: Current node of the pointer to be moved.
 * @size: Number of nodes of the singly linked list.
 * @step: NUmber of steps to move @high.
 * Return: New node of the moved pointer.
 */
listint_t *take_step(listint_t *high, size_t size, size_t step)
{	/* Check if step is greater than the last index of list */
	if (step > size - 1)
		step = size - 1;

	while (high->index < step)
		high = high->next;
	return (high);
}
