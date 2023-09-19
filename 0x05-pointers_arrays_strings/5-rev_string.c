#include "main.h"

/**
 * _str_length - a function that returns the length of a string.
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
	int i, length = _str_length(s);

	for (i = 0; i < length / 2; i++)
	{
		char j;

		j = s[i];
		s[i] = s[length - 1 - i];
		s[length - i - 1] = j;
	}
}
