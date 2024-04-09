#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers using
 * the Binary search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in @array.
 * @value: The value to search for.
 * Return: The index where value is located, otherwise -1 if @value is not
 * present in @array or if @array is NULL.
 * Description: Print the array being searched every time it changes
 * (e.g. at the beginning and when you search a subarray).
 */
int binary_search(int *array, size_t size, int value)
{
	size_t low, mid, high, i;

	if (array == NULL)
		return (-1);
	low = 0;
	high = size - 1;
	while (low <= high && low != size - 1)
	{
		printf("Searching in array: ");
		for (i = low; i <= high; i++)
		{
			if (i == high)
				printf("%d\n", array[i]);
			else
				printf("%d, ", array[i]);
		}
		/* middle index of the array */
		mid = low + (high - 1) / 2;
		/* check if value is present at mid */
		if (array[mid] == value)
			return (mid);
		/* move right if value is greater than value at mid */
		if (array[mid] < value)
			low = mid + 1;
		/* otherwise move left */
		else
			high = mid - 1;
		i = low;
	}
	return (-1);
}
