#include "main.h"

/**
 * _isupper - a function that checks for uppercase character
 * @c: parameter to check.
 * Return: returns 1 if true, else 0.
*/
int _isupper(int c)
{
	int i;

	for (i = 'A'; i <= 'Z'; i++)
	{
		if (c == i)
		{
			return (1);
		}
	}
	return (0);
}
