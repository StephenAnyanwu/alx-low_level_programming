#include <math.h>
#include "main.h"

/**
 * print_number - a function that prints an integer.
 * @n: an integer to be printed.
 * Return: void.
*/
void print_number(int n)
{
	if (n < 0)
	{
		n = -n;
		_putchar('-');
	}
	else if (n == 0)
		_putchar('0');

	int num1 = n, len1 = 0;
	int h, value = n;

	/* calculate the length of integer */
	while (num1 != 0)
	{
		len1++;
		num1 /= 10;
	}
	for (h = 0; h < len1; h++)
	{
		int num2 = value, len2 = 0;
		int num3 = value, new_num = 0;
		int i, rem;

		while (num2 != 0)
		{
			len2++;
			num2 /= 10;
		}
		for (i = 0; i < len2; i++)
		{
			rem = num3 % 10;
			num3 /= 10;
			if (i < (len2 - 1))
			{
				int power = pow(10, i);
				new_num = new_num + rem * power;
			}
		}
		_putchar(rem + '0');
		value = new_num;
		new_num = 0;
		len2 = 0;
	}
}
