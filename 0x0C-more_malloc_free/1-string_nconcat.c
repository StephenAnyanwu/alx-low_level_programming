#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - a function that concatenate two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: the first n bytes of s2 to be concatenated with s1.
 * Return: returns pointer to the concatenated string.
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1_len = 0, s2_len = 0, i;
	char *ptr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	/* find the length of s1 */
	for (i = 0; s1[i] != '\0'; i++)
		s1_len++;
	/* find the length of s2 */
	for (i = 0; s2[i] != '\0'; i++)
		s2_len++;
	ptr = malloc(sizeof(char) * (s1_len + n) + 1);
	if (ptr == NULL)
		return (NULL);
	if (n >= s2_len)
	{
		for (i = 0; s1[i] != '\0'; i++)
			*(ptr + i) = s1[i];
		for (i = 0; s2[i] != '\0'; i++)
			*(ptr + s1_len + i) = s2[i];
		*(ptr + s1_len + i) = '\0';
	}
	else
	{
		for (i = 0; s1[i] != '\0'; i++)
			*(ptr + i) = s1[i];
		for (i = 0; i < n; i++)
			*(ptr + s1_len + i) = s2[i];
		*(ptr + s1_len + i) = '\0';
	}
	return (ptr);
}
