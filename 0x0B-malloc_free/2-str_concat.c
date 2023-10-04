#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - a function that concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: returns a pointer to t concatenated strings, else
 * returns NULL.
*/
char *str_concat(char *s1, char *s2)
{
	int len1 = 0, len2 = 0, count = 0, k, size;
	char *p;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (*(s1 + len1) != '\0')
		len1++;
	count = len1;
	while (*(s2 + len2) != '\0')
	{
		len2++;
		count++;
	}
	size = sizeof(char);
	p = (char *)malloc((count * size) + size);
	if (p != NULL)
	{
		if (count != 0)
		{
			for (k = 0; k < len1; k++)
				*(p + k) = s1[k];
			for (k = 0; k < len2; k++)
				*(p + len1 + k) = s2[k];
			*(p + count) = '\0';
			return (p);
		}
		*p = '\0';
		return (p);
	}
	free(p);
	return (p);
}
