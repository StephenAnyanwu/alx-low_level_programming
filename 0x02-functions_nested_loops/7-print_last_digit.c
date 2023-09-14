#include "main.h"

/**
 * print_last_digit - a func that prints the last
 * digit of a number.
 * @num: parameter to print its last digit.
 *Return: returns 0 if successful
*/
int print_last_digit(int num)
{
	int d = 10;
	int last_digit;

	last_digit = num % d;
	if (num < 0)
		last_digit = -last_digit;
	_putchar(last_digit);
	return (last_digit);
}
