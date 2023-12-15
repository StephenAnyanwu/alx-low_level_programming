#include "main.h"
#include <stdio.h>
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
	unsigned int count = 0;
	int found = 0;

	while (*s)
	{
		char *ptr = accept;

		found = 0;
		while (*ptr)
		{
			if (*ptr == *s)
			{
				found = 1;
				break;
			}
			ptr++;
		}
		if (!found)
			break;
		count++;
		s++;
	}
}
