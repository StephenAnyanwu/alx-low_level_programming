#include "main.h"

/**
 * leet - a function that encodes a string into 1337.
 * @s: a string to encode.
 * Return: returns encoded string.
*/
char *leet(char *s)
{
	char letters[] = {'A', 'E', 'O', 'T', 'L', 'a', 'e', 'o', 't', 'l'};
	char codes[] = {'4', '3', '0', '7', '1', '4', '3', '0', '7', '1'};
	int i;

	for (i = 0; i <= 10; i++)
	{
		int j = 0;

		while (s[j] != '\0')
		{
			if (s[j] == letters[i])
			{
				s[j] = codes[i];
			}
			j++;
		}
		s[j] = '\0';
	}
	return (s);
}
