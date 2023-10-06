#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * check_digit - a func that check digits in a string.
 * @str: string to check.
 * Return: returns 1 if all char in string are digits,
 * else returns 0.
*/
int check_digit(char *str)
{
	int i = 0, str_len, len = 0;
	char digits[] = "0123456789";

	while (str[i] != '\0')
	{
		int j = 0;

		for (j = 0; j < 10; j++)
		{
			if (str[i] == digits[j])
				len++;
		}
		i++;
	}
	str_len = strlen(str);
	if (len == str_len)
		return (1);
	return (0);
}

/**
 * main - a  program that adds positive numbers.
 * @argc: argument counter.
 * @argv: argument vector.
 * Return: returns 0 on success.
*/
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc < 2)
		printf("%d\n", 0);
	if (argc >= 2)
	{
		for (i = 1; i < argc; i++)
		{
			int chk =  check_digit(argv[i]);

			if (chk == 0)
			{
				printf("Error\n");
				return (1);
			}
			if (chk == 1)
				sum += atoi(argv[i]);
		}
		printf("%d\n", sum);
	}
	return (0);
}
