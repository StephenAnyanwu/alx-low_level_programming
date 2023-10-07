#include "main.h"

/**
 * _strcat - a function that concatenates two strings.
 * @dest: the first string.
 * @src: the second string.
 * Return: returns the concatenated strings.
*/
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int src_len = 0;
	int i = 0;

	for (i = 0; dest[i]; i++)
		dest_len++;
	for (i = 0; src[i]; i++)
		src_len++;
	for (i = 0; i <= src_len; i++)
		dest[dest_len + i] = src[i];
	return (dest);
}
