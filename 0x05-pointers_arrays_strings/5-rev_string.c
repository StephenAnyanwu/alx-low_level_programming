#include "main.h"
#include <unistd.h>

/**
 * _strlen - a function that returns the length of a string.
 * @str: a string (parameter).
 * Return: returns an integer (length of s).
*/
int _str_length(char *str)
{
	int i = 0, count = 0;

	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

/**
 * rev_string - a function that prints a string, in reverse.
 * @s: a pointer to a string (parameter).
*/
void rev_string(char *s)
{
	int length = _str_length(s), i, idx;

	for (i = 0; i < length; i++)
	{
		idx = length - (i + 1);
		_putchar(s[idx]);
	}
	_putchar('\n');
}
