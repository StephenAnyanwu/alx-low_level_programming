#include "main.h"
#include <string.h>

/**
 * _strncat - a function that concatenates two strings.
 * @dest: the first string.
 * @src: the second string.
 * @n:number of bytes from the second string that is to
 * be concatenated with the first string.
 * Return: returns the pointer of the concatenated strings.
*/
char *_strncat(char *dest, char *src, int n)
{
	int i;
        int dest_len = strlen(dest);

	for (i = 0; i < n && *src != '\0'; i++)
	{
		dest[dest_len + i] = *src;
		src++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
