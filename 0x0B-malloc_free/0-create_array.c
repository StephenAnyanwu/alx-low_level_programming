#include "main.h"
#include <stdlib.h>

/**
 * create_array - a function that creates an array of chars and initializes
 * it with a specific char.
 * @size: size of the array.
 * @c: a char to initialize the array with.
 * Return:returns NULL if size = 0, a pointer to the array or NULL if it fails.
*/
char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;

	ptr = (char *)malloc(size * sizeof(char));
	if (size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		*(ptr + i) = c;
	return (ptr);
}
