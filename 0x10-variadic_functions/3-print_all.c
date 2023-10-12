#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * print_all - a function that prints any argument given
 * to it.
 * @format: the argument format specifier.
*/
void print_all(const char * const format, ...)
{
	int i = 0, chk;
	char *str;
	va_list args;

	va_start(args, format);
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'i':
				printf("%d", va_arg(args, int));
				chk = 0;
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				chk = 0;
				break;
			case 'c':
				printf("%c", va_arg(args, int));
				chk = 0;
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				chk = 1;
				break;
		}
		if (format[i + 1] != '\0' && chk == 0)
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(args);
}
