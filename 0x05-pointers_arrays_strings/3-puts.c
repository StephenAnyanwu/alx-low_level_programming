#include "main.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: a pointer to the string (parameter).
 * Return: return an integer
*/
int _strlen(char *s)
{
	int str_len = 0;

	while (*s)
	{
		str_len++;
		s++;
	}
	return (str_len);
}

/**
 * _puts - a function that prints a string.
 * @str: a pointer of the string that is to be  printed (parameter).
*/
void _puts(char *str)
{
	int str_len;
	int i;

	str_len = _strlen(str);
	for (i = 0; i < str_len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
