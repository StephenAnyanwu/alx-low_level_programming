#include "main.h"

/**
 * _strstr - a function that finds the occurance of a substring
 * in another string.
 * @haystack: a string that is to be scanned.
 * @needle: a substring that is to be scanned for.
 * Return: returns a pointer to the beginning of the located
 *substring, or NULL if the substring is not found.
*/
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *start = haystack;
		char *substring = needle;

		while (*haystack && *substring && *haystack == *substring)
		{
			haystack++;
			substring++;
		}
		if (!*substring)
			return (start);
		haystack = start + 1;
	}
	return (NULL);
}
