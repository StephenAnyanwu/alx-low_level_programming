#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _strdup - a function that duplicates a string.
 * @str: a string to be duplicated.
 * Return: returns a pointer to the duplicated string.
*/
char *_strdup(char *str)
{
	int i, len = 0, size;
	char *p;

	/* calculate the length of str*/
	while (str[len] != '\0')
		len++;
	if (str == NULL)
		return (NULL);
	size = sizeof(char);
	p = (char *)malloc((len * size) + size);
	if (p != NULL)
	{
		if (len != 0)
		{
			for (i = 0; i < len; i++)
				*(p + i) = str[i];
			*(p + len) = '\0';
			return (p);
		}
		p = (char *)malloc(1 * sizeof(char));
		*p = '\0';
		return (p);
	}
	free(p);
	return (NULL);
}
