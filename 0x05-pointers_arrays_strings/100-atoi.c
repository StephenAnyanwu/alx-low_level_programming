#include "main.h"

/**
 * _atoi - convert a string to an integer.
 * @s: string to be converted.
 * Return: integer while taking - and + into account,
 * or 0 if there is no numbers in the string.
*/
int _atoi(char *s)
{
	int i, neg_count, num, len, digit, f;

	i = 0;
	neg_count = 0;
	num = 0;
	len = 0;
	digit = 0;
	f = 0;
	while (s[len] != '\0') /* find length of s */
		len++;
	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++neg_count;
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (neg_count % 2) /* if number of '-' is odd */
				digit = -digit;
			num = num * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0) /* if no digit is found in s */
		return (0);
	return (num);
}
