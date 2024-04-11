#include "search_algos.h"

int min(int a, int b);
int binarySearch(int *subarray, size_t low, size_t high, int value);

/**
 * exponential_search - earches for a value in a sorted array of integers
 * using the Exponential search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in @array.
 * @value: The value to search for.
 * Return: The first index where @value is located, otherwise -1 if @value is
 * not present in @array or if @array is NULL.
 * Description:
 * Every time you compare a value in the array to the value you are
 * searching for, you have to print this value.
 * Once you’ve found the good range, you need to use a binary search:
 * Every time you split the array, you have to print the new array
 * (or subarray)you’re searching in.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);
	/* check if first element of array is value */
	if (array[0] == value)
	{
		printf("Value checked array[0] = [%d]", array[0]);
		printf("Found %d at index: 0", array[0]);
		return (0);
	}
	i = 1;
	while (i < size && array[i] <= value)
		i *= 2;
	return (binarySearch(array, i / 2, min(i, size - 1), value));
}

/**
 * min - Finds the minimum of two numbers.
 * @a: First number.
 * @b: Second number.
 * Return: The mininum number.
 */
int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * binarySearch - Performs a binary search on a subarray.
 * @subarray: The subarray to search in
 * @low: Low index of the subarray.
 * @high: High index of the subarray.
 * @value: Value to search for.
 * Return: The index of the value, otherwise -1.
 */
int binarySearch(int *subarray, size_t low, size_t high, int value)
{
	size_t mid, i;

	printf("Value found between indexes [%ld] and [%ld]\n", low, high);
	while (low <= high)
	{
		printf("Searching in array: ");
		for (i = low; i < high; i++)
			printf("%d, ", subarray[i]);
		printf("%d\n", subarray[i]);

		/* middle index of the array */
		mid = low + (high - low) / 2;
		/* check if value is present at mid */
		if (subarray[mid] == value)
			return (mid);
		/* move right if value is greater than value at mid */
		if (subarray[mid] < value)
			low = mid + 1;
		/* otherwise move left */
		else
			high = mid - 1;
		i = low;
	}
	return (-1);
}
