#include "main.h"

/**
 * prime_num - a function that checks if a number is a prime number.
 * @num: number to check.
 * @i: an iterating value.
 * Return: returns 1 if num is prime, else returns 0.
*/
int prime_num(int num, int i)
{
	if (num == i)
		return (1);
	if ((num != i && num % i == 0) || num <= 1)
		return (0);
	return (prime_num(num, i + 1));
}

/**
* is_prime_number - a function that checks if a number is a prime number.
* @n: the main number to check.
* Return: returns 1 if n is a prime number, else returns 0.
*/
int is_prime_number(int n)
{
	return (prime_num(n, 2));
}
