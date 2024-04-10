#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using the Interpolation search algorithm.
 * @array: A pointer to the first element of the @array to search in.
 * @size: The number of elements in @array.
 * @value: The value to search for.
 * Return: The first index where value is located, otherwise -1 if value is not
 * present in array or if array is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, pos;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;
	while (1)
	{
		pos = ((value - array[low]) * (high - low) /
				(array[high] - array[low])) + low;
		if (pos > size - 1)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

}
