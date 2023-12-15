#include "main.h"

/**
 * _strlen - a function that returns the length of a string.
 * @s: a pointer to the string (parameter).
 * Return: returns integer (string length).
*/
int _strlen(char *s)
{
	int str_len = 0;

	while (*s)
	{
		s++;
		str_len++;
	}
	return (str_len);
}
