#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - a function that sums all of its parameters.
 * @n: number of argument passed to sum_them_all function.
 * Return: returns the summed value.
*/
int sum_them_all(const unsigned int n, ...)
{
	unsigned int sum = 0, i;
	va_list args;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (n == 0)
			return (0);
		sum += va_arg(args, const unsigned int);
	}
	va_end(args);
	return (sum);
}

