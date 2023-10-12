#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - a function that prints integers.
 * @separator: a sstring to be printed between integers.
 * @n: number of integers to be printed.
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i, integer;
	va_list args;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		integer = va_arg(args, const unsigned int);
		printf("%d", integer);
		if (separator != NULL && i != (n - 1))
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
