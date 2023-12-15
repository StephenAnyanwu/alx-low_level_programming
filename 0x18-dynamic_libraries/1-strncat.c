#include "main.h"

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
	int j = 0;
	int dest_len = 0;

	while (dest[dest_len] != '\0')
		dest_len++;
	while (j < n && src[j] != '\0')
	{
		dest[dest_len] = src[j];
		dest_len++;
		j++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
