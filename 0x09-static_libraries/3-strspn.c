#include "main.h"

/**
 * _strspn - a function that calculates the length (i.e number of bytes)
 * of the initial segment of s, which consists only of characters(ie bytes)
 *from accept.
 * @s: a string to be scanned.
 * @accept: a string containing the characters to be matched.
 * Return: returns the number of characters in the initial segment of str1 
 *which consist only of characters from str2.
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; s[i] != accept[j]; j++)
		{
			if (accept[j] == '\0')
				return (i);
		}
	}	
	return (0);
}
