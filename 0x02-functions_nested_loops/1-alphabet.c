#include "main.h"

/**
 * print_alphabet - this function prints lowcase alphabets
 * Return: returns nothing
*/
void print_alphabet(void)
{
	char alphabet;

	for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
		_putchar(alphabet);
	_putchar('\n');
}
