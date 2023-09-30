#include "main.h"

/**
 * _strlen_recursion - a function that finds the length of a string.
 * @s: the string to find its length.
 * Returns: returns string's length.
*/
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
/**
 * str_compare - compare each character of a string.
 * @s: a string.
 * @i: small iterating value,
 * @j: large iterating value.
 * Return: returns integer.
*/
int str_compare(char *s, int i, int j)
{
	if (*(s + i) == *(s + j))
	{
		if (i == j || j == i + 1)
			return (1);
		return (0 + str_compare(s, i + 1, j - 1));
	}
	return (0);
}

/**
 * is_palindrome - a function that checks if a string is palindrome.
 * @s: the string to check.
 * Return: returns 1 if true else returns 0.
*/
int is_palindrome(char *s)
{
	return (str_compare(s, 0, _strlen_recursion(s) - 1));
}
