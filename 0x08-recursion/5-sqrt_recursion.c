#include "main.h"


/**
 * sqrt_num - a function that calculate the square root of a number.
 * @num: number to be calculated.
 * @val: an iterator.
 * Return: returns -1 if num does not have a natural square root, else
 * returns the calculated value.
*/
int sqrt_num(int num, int val)
{
	int check = val * val;

	if (check == num)
		return (val);
	if (check > num)
		return (-1);
	return (sqrt_num(num, val + 1));
}

/**
 * _sqrt_recursion - a function that calculate the square of a number.
 * @n: the number to calculate its square root.
 * Return: returns -1 if n does not have a natural square root, else
 * returns the calculated value.
*/
int _sqrt_recursion(int n)
{
	return (sqrt_num(n, 0));
}
