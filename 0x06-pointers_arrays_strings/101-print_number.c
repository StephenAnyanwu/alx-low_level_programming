#include "main.h"

/**
 * print_number - a function that prints an integer.
 * @n: an integer to be printed.
 * Return: void.
*/
void print_number(int n)
{
	int num = n;
	int i, j, num1, num2, len1 = 0, len2, rem;

	if (num < 0)
	{
		num = -num;
		_putchar('-');
	}
	if (num == 0)
		_putchar('-');
	else
	{
		num1 = num;
		num2 = num;
		while (num1 != 0)
		{
			len1++;
			num /= 10;
		}
		len2 = len1;
		for (i = 0; i < len1; i++)
		{
			for (j = 0; j < len2; j++)
			{
				rem = num2 % 10;
				num2 = num2 / 10;
			}
			_putchar(rem + '0');
			num2 = num;
			len2--;
		}
	}

}
