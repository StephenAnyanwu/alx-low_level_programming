#include <stdio.h>

/**
 * array_iterator - a function that executes a function
 * given as a parameter on each element of an array.
 * @array: an array.
 * @size: size of  the array.
 * @action: a function to perform on each element of array.
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int idx;

	if (array == NULL || action == NULL)
		return;
	for (idx = 0; idx < size; idx++)
		action(array[idx]);
}
