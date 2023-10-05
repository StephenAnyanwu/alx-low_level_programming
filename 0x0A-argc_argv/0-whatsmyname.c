#include "main.h"
#include <stdio.h>

/**
 * main - the main function. A  program that prints its name.
 * @argc: argument counter.
 * @argv: argument vector.
 * Return: returns 0 on success.
*/
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		if (i == 0)
			printf("%s\n", argv[i]);
	return (0);
}
