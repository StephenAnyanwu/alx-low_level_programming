#include "main.h"
#include <stdlib.h>

/**
 * argstostr - a function that concatenates all of its arguments.
 * @ac: argument count.
 * @av: argument vector.
 * Return: returns a pointer to the new string or NULL if it fails.
*/
char *argstostr(int ac, char **av)
{
	int i, j, k, l;
	char *p;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
		for (j = 0; av[i][j]; j++)
			l++;
	l += ac;
	p = malloc(sizeof(char) * l + 1);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			p[k] = av[i][j];
			k++;
		}
		if (p[k] == '\0')
			p[k++] = '\0';
	}
	return (p);
}
