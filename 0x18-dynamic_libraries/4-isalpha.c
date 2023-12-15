#include "main.h"

/**
 * _isalpha - a func that checks for alphabetic charater
 * @c: parameter to be checked
 * Return: returns 1 if true, 0 if false
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
