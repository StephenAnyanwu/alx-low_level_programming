#include "main.h"

/**
 * _strcpy - a function that copies the string pointed.
 * @dest:destination (first parameter).
 * @src: source (second parameter).
 * Return: the pointer to dest.
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
