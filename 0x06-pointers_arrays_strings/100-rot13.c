#include "main.h"
#include <stdio.h>
/**
 * rot13 - a function that encodes a string using rot13.
 * @s: string to be encodes.
 * Return: the encoded string.
*/
char *rot13(char *s)
{
	char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
		'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c',
		'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
		'x', 'y', 'z'};
	char rot[] = {'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F',
		'G', 'H', 'I', 'J', 'K', 'L', 'M', 'n', 'o', 'p',
		'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		'k', 'l', 'm'};
	unsigned long int i;
	int j = 0;

	while (s[j] != '\0')
	{
		for (i = 0; i < sizeof(ch); i++)
			if (s[j] == ch[i])
			{
				s[j] = rot[i];
				break;
			}
		j++;
	}
	return (s);
}
