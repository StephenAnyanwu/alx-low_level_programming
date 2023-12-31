#include "main.h"

/**
 * _strchr - a function that finds the first occurance of a
 * character in a string.
 * @s: a string to be searched.
 * @c: a character be be searched for in s.
 * Return: returns a pointer to the first occurrence of the
 *character c in the string str, or NULL if the character is not found.
*/
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}
