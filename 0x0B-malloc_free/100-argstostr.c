#include "main.h"
#include <stdlib.h>

/**
 * argstostr - a function that concatenates all of its arguments.
 * @ac: argument count.
 * @av: a pointer to argument vector.
 * Return: returns a pointer to the new string or NULL if it fails.
*/
char *argstostr(int ac, char **av)
{
	int i, j, k, len = 0;
	char *p, *str;

	if (ac == 0 || av == NULL)
		return (NULL);
	/* calculating the length of the arguments (av) all together */
	for (i = 0; i < ac; i++)
	{
		p = av[i];
		j = 0;
		while (p[j++])
			len++;
		len++;
	}
	/* allocating memory where to store the arguments (av) */
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	/* appending the arguments (av) to str */
	for (i = 0, j = 0; i < ac && j < len; i++)
	{
		p = av[i];
		k = 0;
		while (p[k])
		{
			str[j] = p[k];
			k++;
			j++;
		}
		/* append a newline after end of each argument append */
		str[j++] = '\n';
	}
	/* append a null char at the end of the last appended argument*/
	str[j] = '\0';
	return (str);
}
