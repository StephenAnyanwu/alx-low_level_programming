#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * alloc_grid - a function that returns a pointer to
 * a 2 dimensional array of integers.
 * @width: array width.
 * @height: array height.
 * Return: returns NULL if width or height is 0 or negative.
*/
int **alloc_grid(int width, int height)
{
	int i, j, **p;

	if (width <= 0 || height <= 0)
		return (NULL);
	p = malloc(sizeof(int *));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		p[i] = malloc(sizeof(int));
		if (p[i] == NULL)
		{
			for (i--; i >= 0; i--)
			free(p[i]);
			free(p);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			p[i][j] = 0;
	return (p);
}
