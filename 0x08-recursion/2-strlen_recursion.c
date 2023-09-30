#include "main.h"

/**
 *  _strlen_recursion - a function that calculate the length ot a string.
 *  @s: a string that its length will to be caculated.
 *  Return: return the length (integer) of the string.
*/
int _strlen_recursion(char *s)
{
	if (*s != '\0')
		return (1 + _strlen_recursion(s + 1));

	return (0);
}

