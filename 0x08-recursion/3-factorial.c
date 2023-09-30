#include "main.h"

/**
 * factorial - a function that calculates the factorial of a given number.
 * @n: the number that will be calculated.
 * Return: returns the factorial of s (integer).
*/
int factorial(int n)
{
	if (n >= 1)
		return (n * factorial(n - 1));
	else if (n == 0)
		return (1);
	else
		return (-1);
}
