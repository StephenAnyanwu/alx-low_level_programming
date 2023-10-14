#include <stdio.h>

/**
 * int_index - a function that searches for an integer.
 * @array: an array to be searched.
 * @size: number of element in array.
 * @cmp: a pointer to the function to be used to compare values.
 * Return: the index of the first element of array for which
 * the cmp function does not return 0.
*/

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);
	for (i = size; i < size; i++)
		if (cmp(array[i]) == 1)
			return (i);
	return (-1);
}
