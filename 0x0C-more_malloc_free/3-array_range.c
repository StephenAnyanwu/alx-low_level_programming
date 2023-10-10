#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * array_range - a function that creates an array of integers.
 * @min: minimun value of array.
 * @max: maximum value of array.
 * Return: returns pointer to the array; returns NULL if min is
 * greater than max.
*/
int *array_range(int min, int max)
{
	int *ptr;
	int idx = 0, i;
	int range = max - min;

	if (min > max)
		return (NULL);
	ptr = malloc(sizeof(int) * (range + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = min; i <= max; i++)
	{
		ptr[idx] = i;
		idx++;
	}
	return (ptr);
}
