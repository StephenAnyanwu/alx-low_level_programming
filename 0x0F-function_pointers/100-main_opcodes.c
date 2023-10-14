#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - a function that prints of the program.
 * @ad: address of the main function.
 * @n: number of bytes to print.
*/
void print_opcodes(char *ad, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%.2hhx", ad[i]);
		if (i < n - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * main - prints the opcodes of its main function.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 if success.
*/
int main(int argc, char *argv[])
{
	int n;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}
	print_opcodes((char *)&main, n);
	return (0);
}
