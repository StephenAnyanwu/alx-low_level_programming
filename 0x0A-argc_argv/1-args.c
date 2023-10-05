#include "main.h"
#include <stdio.h>

/**
 * main - the main function. A program that prints
 *the number of arguments passed into it.
 * @argc: argument counter.
 * @argv: argument vector.
 * Return: returns 0 on success.
*/
int main(int argc, char *argv[])
{
	int j, i = 0;

	if (argc == 1)
	{
		printf("%d\n", i);
	}
	else
	{
		for (j = 0; j < (argc - 1); j++)
			i++;
		printf("%d\n", i);
	}
	(void)argv;
	return (0);
}
