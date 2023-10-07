#include "main.h"

/**
 * _strcmp - a function that compares string arguments character by character.
 * @s1: first string.
 * @s2: second string.
 * Return: returns negative integer if s1<s2, positive integer if
 * s1>s2 or zero if s1=s2.
*/
int _strcmp(char *s1, char *s2)
{
	int i;
	int value = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			value = s1[i] - s2[i];
			return (value);
		}
	}
	return (value);
}
