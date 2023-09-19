#include "main.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: a pointer to a string (parameter).
 * Return: returns an integer (length of s).
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
 * print_rev - a function that prints a string, in reverse.
 * @s: a pointer to a string (parameter).
*/
void print_rev(char *s)
{
	int str_len;
	int i;
	int idx;

	str_len = _strlen(s);
	for (i = 0; i < str_len; i++)
	{
		idx = str_len - (i + 1);
		_putchar(s[idx]);
	}
	_putchar('\n');
}
