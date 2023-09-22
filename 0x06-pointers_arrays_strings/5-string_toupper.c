#include "main.h"

/**
 * string_toupper - a function that changes all
 * lowercase letters of a string to uppercase.
 * @s: a string to change to uppercase.
 * Return: returns an uppercase string (a pointer).
*/
char *string_toupper(char *s)
{
	char uppercase[26] = "";
	char lowercase[26] = "";
	char i;
	int n, j = 0;

	for (i = 'A'; i <= 'Z'; i++)
	{
		uppercase[j] = i;
		j++;
	}
	j = 0;
	for (i = 'a'; i <= 'z'; i++)
	{
		lowercase[j] = i;
		j++;
	}
	n = 0;
	while (s[n] != '\0')
	{
		int k = 0;

		while (lowercase[k] != '\0')
		{
			if (lowercase[k] == s[n])
			{
				s[n] = uppercase[k];
			}
			k++;
		}
		n++;
	}
	s[n] = '\0';
	return (s);
}
