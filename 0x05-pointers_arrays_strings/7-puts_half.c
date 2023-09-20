#include "main.h"

/**
 * puts_half - a function that prints the second half of a string.
 * @str: a string to be printed.
 * Return: void.
*/
void puts_half(char *str)
{
	int i, n, length_of_the_string = 0;

	for (i = 0; str[i] != '\0'; i++)
		length_of_the_string++;
	n = (length_of_the_string - 1) / 2;
	for (i = n + 1; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}
