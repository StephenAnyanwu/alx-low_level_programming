#include "main.h"

/**
 * _isdigit - a funtion that checks for a digit
 * @c: paramter (digit) to check.
 * Return: returns 1 if c is true else 0.
*/
int _isdigit(int c)
{
	int i;
	int j;

	for (i = 0; i <= 9; i++)
	{
		if (c == i)
		{
			return (1);
		}
	}
	for (j = '0'; j <= '9'; j++)
	{
		if (c == j)
		{
			return (1);
		}

	}
	return (0);
}
