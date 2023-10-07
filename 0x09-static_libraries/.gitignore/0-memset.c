#include "main.h"

/**
 *_memset - a function that fills a block of
 *memory with a particular value.
 *@s: starting address of memory to be filled.
 *@b: value to be filled.
 *@n: number of bytes to be filled starting from s.
 *Return: returns s filled with s.
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
