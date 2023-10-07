#include "main.h"

/**
 * _memcpy - a function that copies a block of data from
 * a source address to a destination address.That is, it
 * copies a block of memory from one location to another
 * @dest: a pointer to the memory location where the
 * copied data will be stored.
 * @src: a pointer to the memory location from where the
 * data is to be copied.
 * @n: number of bytes to be copied.
 * Return: returns a pointer to the memory location where
 * data is copied.
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
