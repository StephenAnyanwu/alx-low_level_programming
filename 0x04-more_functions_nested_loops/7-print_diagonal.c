#include "main.h"

/**
 * print_diagonal - a func that print diagonal line.
 * @n: number of lines to be printed (parameter).
 * Return: returns nothing.
*/
void print_diagonal(int n)
{
	int i;
	int j;

	if (n <= 0)
		_putchar('\n');
	else if (n > 0)
	{
		i = 1;
		while (i <= n)
		{
			for (j = 1; j <= i; j++)
			{
				if (j == i)
				{
					_putchar('\\');
				}
				else
				{
					_putchar(' ');
				}
			}
			_putchar('\n');
			i++;
		}
	}
}
