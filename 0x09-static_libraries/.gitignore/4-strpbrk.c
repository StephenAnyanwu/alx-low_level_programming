#include "main.h"

/**
 * _strpbrk - a function that locates the first character in
 * string s that matches any specified in accept, excluding
 * the terminating null character.
 * @s: a string to be scanned.
 * @accept: a string containing the character to match.
 * Return: returns a pointer to the character in s that matches
 *one of the characters in accept or NULL if no such charater is
 *found.
*/
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		const char *c = accept;

		while (*c != '\0')
		{
			if (*s == *c)
				return (s);
			c++;
		}
		s++;
	}
	return (NULL);
}
