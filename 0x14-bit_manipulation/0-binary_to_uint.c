#include "main.h"

/**
 * binary_to_uint -  a function that converts a binary
 * number to an unsigned int.
 * @b: a pointer to a string of 0 and 1 chars.
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL.
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int dec = 0, exp = 1;
	int i, len = 0;

	if (b == NULL)
		return (0);
	/*calculate the length of b*/
	for (i = 0; *(b + i) != '\0'; i++)
		len++;
	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] == '1' || b[i] == '0')
		{
			if (*(b + i) == '1')
			{
				dec += exp;
				exp *= 2;
			}
			if (*(b + i) == '0')
				exp *= 2;
		}
		else
			return (0);
	}
	return (dec);
}
