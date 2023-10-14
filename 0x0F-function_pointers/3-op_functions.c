#include "3-calc.h"

/**
 * op_add - a function that add two integers.
 * @a: first integer.
 * @b: second integer.
 * Return: summed value.
*/
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - a function find the difference of two integers.
 * @a: first integer.
 * @b: second intege r.
 * Return: differenc of a and b.
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - a function that finds the product of two integers.
 * @a: first integer.
 * @b: second integer.
 * Return: product of a and b.
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - a function that finds the division of integer.
 * @a: first integer.
 * @b: second integer.
 * Return: a divided by b.
*/
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - a function that finds remainder of division of two integers.
 * @a: first integer.
 * @b: second integer.
 * Return: remainder of a divided by b.
*/
int op_mod(int a, int b)
{
	return (a % b);
}
