#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - a function that reallocates a memory block
 * using malloc and free.
 * @ptr: a pointer to the memory previously allocated.
 * @old_size: size in bytes of the allocated space for ptr.
 * @new_size: new size in bytes of the new memory block.
 * Return: returns pointer to the newly allocated memory.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pt;
	size_t i, max = new_size;
	char *old_pt = ptr;

	if (ptr == NULL)
	{
		pt = malloc(new_size);
		return (pt);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	pt = malloc(new_size);
	if (pt == NULL)
		return (NULL);
	if (new_size > old_size)
		max = old_size;
	for (i = 0; i < max; i++)
	{
		pt[i] = old_pt[i];
	}
	free(ptr);
	return (pt);
}
