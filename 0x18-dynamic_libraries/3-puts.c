#include "main.h"

/**
 * _puts - a function that prints a string.
 * @str: a pointer of the string that is to be  printed (parameter).
*/
void _puts(char *str)
{
	int str_len = 0;
	char *s = str;
	int i;

	while (*s)
	{
		str_len++;
		s++;
	}
	str_len = _strlen(str);
	for (i = 0; i < str_len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
