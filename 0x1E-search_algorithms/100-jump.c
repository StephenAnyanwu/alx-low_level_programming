#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in @array.
 * @value: The value to search for.
 * Return: The first index where value is located, otherwise -1 if @value
 * is not present in @array or if @array is NULL.
 * Description: Every time you compare a value in the array to the value you
 * are searching for, you have to print this value.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev;

	if (array == NULL)
		return (-1);
	step = sqrt(size);
	prev = 0;
	printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
	while (1)
	{
		if (step > size - 1 || array[step] >= value)
		{
			printf("Value found between indexes [%ld] and [%ld]\n", prev, step);
			/* if step exceeds last index of array, turn it to last index */
			if (step > size - 1)
				step = size - 1;
			while (prev <= step)
			{
				printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
				if (array[prev] == value)
					return (prev);
				prev++;
			}
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", step, array[step]);
		prev = step;
		step += sqrt(size);
	}
}
