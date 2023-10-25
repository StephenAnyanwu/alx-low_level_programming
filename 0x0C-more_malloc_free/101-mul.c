#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * left_move_print - a function that moves a string one place to the
 * left and prints the string.
 * @str: string to move.
 * @size: size of string to move.
*/
void left_move_print(char *str, int size)
{
	int i, j;

	i = j = 0;
	while (i < size)
	{
		if (str[i] != '0')
			j = 1;
		if (j || i == size - 1)
			_putchar(str[i]);
		i++;
	}
	_putchar('\n');
	free(str);
}

/**
 * mul - a function that multiplies a char with a string and place
 * the result int dest.
 * @n: char to multiply.
 * @num: string to multiply.
 * @num_index: last non NULL index of num.
 * @dest: destination of multiplication.
 * @dest_index: highest index to start addition.
 * Return: pointer to dest, or NULL on failure.
*/

char *mul(char n, char *num, int num_index, char *dest, int dest_index)
{
	int j, k, mul, mulrem, add, addrem;

	mulrem = addrem = 0;
	for (j = num_index, k = dest_index; j >= 0; j--, k--)
	{
		mul = (n - '0') * (num[j] - '0') + mulrem;
		mulrem = mul / 10;
		add = (dest[k] - '0') + (mul % 10) + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	for (addrem += mulrem; k >= 0 && addrem; k--)
	{
		add = (dest[k] - '0') + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	if (addrem)
		return (NULL);
	return (dest);
}

/**
 * check_for_digits - a function that checks the argument to ensure
 * they are digits.
 * @av: a pointer to argument.
 * Return: 0 if digit, 1 if not.
*/

int check_for_digits(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
		for (j = 0; av[i][j]; j++)
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
	return (0);
}

/**
 * init - a function that initializes a string.
 * @str: string to initialize.
 * @len: length of string.
*/

void init(char *str, int len)
{
	int i;

	for (i = 0; i < len; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - a function (the main function) that multiplies two numbers.
 * @argc: argument count;
 * @argv: argument vector.
 * Return: 0 or exit status of 98 if failure.
*/

int main(int argc, char *argv[])
{
	int l1, l2, ln, ti, i;
	char *a, *t, e[] = "Error\n";

	if (argc != 3 || check_for_digits(argv))
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}
	for (l1 = 0; argv[1][l1]; l1++)
		;
	for (l2 = 0; argv[1][l2]; l2++)
		;
	ln = l1 + l2 + 1;
	a = malloc(sizeof(char) * ln);
	if (a == NULL)
	{
		for (ti = 0; e[ti]; ti++)
			_putchar(e[ti]);
		exit(98);
	}
	init(a, ln - 1);
	for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)
	{
		t = mul(argv[2][ti], argv[1], l1 - 1, a, (ln - 2) - i);
		if (t == NULL)
		{
			for (ti = 0; e[ti]; ti++)
				_putchar(e[ti]);
			free(a);
			exit(98);
		}
	}
	left_move_print(a, ln - 1);
	return (0);
}
