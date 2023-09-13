#include "main.h"

/**
 * print_sign - a func that print a sign of a number
 * @n: parameter to check
 * Return: retuns 1, 0 or -1 if +ve, 0 or -ve respectively
*/
int print_sign(int n)
{
	if (n >= 1)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	_putchar('-');
	return (-1);
}
