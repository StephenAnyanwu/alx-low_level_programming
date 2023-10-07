#include "main.h"

/**
 * _islower - this func checks for lowercase character
 * @c: parameter
 * Return: returns 1 if true, 0 if false
*/
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
