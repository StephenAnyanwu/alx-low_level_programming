#include "main.h"

/**
 * print_triangle - a func that prints triangle.
 * @size: size of the triangle (parameter).
 * Return: returns nothing.
*/
void print_triangle(int size)
{
	int i, j;
	int k = size;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size; j++)
		{
			if (j >= k)
				_putchar('#');
			else
				_putchar(' ');
		}
		_putchar('\n');
		k--;
	}
}
