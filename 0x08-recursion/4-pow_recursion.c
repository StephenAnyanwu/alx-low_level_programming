#include "main.h"

/**
 * _pow_recursion - a function that calculate the value of x raised to the
 * power of y.
 * @x: an integer base value.
 * @y: an integer power value.
 * Return: returns -1 if y is less than 0, else returns the value.
*/
int _pow_recursion(int x, int y)
{
	if ((x < 0 && y > 1) || (x >= 0 && y > 1))
		return (x * _pow_recursion(x, y - 1));
	if (x < 0 && y == 1)
		return (x);
	if ((x < 0 || x >= 0) && y == 0)
		return (1);
	if (x >= 0 && y == 1)
		return (x);
	if (y < 0)
		return (-1);
	return(0);
}
