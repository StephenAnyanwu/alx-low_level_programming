#include "main.h"

/**
 * _puts - a function that prints a string.
 * @str: a pointer of the string that is to be  printed (parameter).
*/
void _puts(char *str)
{
	int i;
	int str_length;

	str_length = _strlen(str);
	for (i = 0; i < str_length; i++)
		_putchar(str[i]);
	_putchar('\n');
}
