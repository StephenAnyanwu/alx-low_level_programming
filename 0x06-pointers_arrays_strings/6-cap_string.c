#include "main.h"

/**
 * char_toupper - a function that  converts a lowercase character to uppercase.
 * @c: a charater that will be converted.
 * Return: returns uppercase charater.
*/
char char_toupper(char c)
{
	char uppercase[26] = "";
	char lowercase[26] = "";
	char i;
	int k, j = 0;
	char ch = c;

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
	for (k = 0; k <= 26; k++)
	{
		if (lowercase[k] == ch)
		{
			ch = uppercase[k];
		}
	}
	return (ch);
}

/**
 * cap_string -  a function that capitalizes all words of a string.
 * @str: a sring to capitalize.
 * Return: a capitalized string.
*/
char *cap_string(char *str)
{
	char ch[] = {' ', ',', ';', '.', '!', '?', '"', '(', ')', '{', '}', '\n', '\t'};
	int idx = 0;
	int n;

	while (str[idx] != '\0')
	{
		if (str[idx] >= 'a' || str[idx] <= 'z')
		{
			if (idx == 0)
				str[0] = char_toupper(str[0]);
			for (n = 0; n <= 13; n++)
			{
				if (str[idx - 1] == ch[n])
					str[idx] = char_toupper(str[idx]);
			}
		}
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
