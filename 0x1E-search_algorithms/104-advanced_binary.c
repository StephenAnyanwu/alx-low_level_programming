#include "search_algos.h"

int advanced_binary_recursive(int *array, size_t low, size_t high, int value);

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in @array.
 * @value: The value to search for.
 * Return: The first index where value is located, otherwise -1 if @value
 * is not present in @array or if @array is NULL.
 * Description: Every time you split the array, you have to print the new
 * array (or subarray) you’re searching in.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}

/**
 * advanced_binary_recursive - Recursively search for a value in a sorted array
 * of integers.
 * @array: A pointer to the first element of the array to search in.
 * @low: Low index of the array.
 * @high: High index of the array.
 * @value: The value to search for.
 * Return: The first index where the value is located, otherwise -1 if value is
 * not present in the array.
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (low <= high)
	{
		printf("Searching in array: ");
		for (i = low; i < high; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);
		/* middle index of the array */
		mid = low + (high - low) / 2;
		/* check if value is present at mid */
		if (array[mid] == value)
		{
			while (array[mid - 1] == value)
				/* if value is also at mid-1, */
				/*move mid to right*/
				--mid;
			return (mid);
		}
		if (array[mid] < value)
			return (advanced_binary_recursive(array, mid + 1, high, value));
		return (advanced_binary_recursive(array, low, mid - 1, value));
	}
	return (-1);
}
