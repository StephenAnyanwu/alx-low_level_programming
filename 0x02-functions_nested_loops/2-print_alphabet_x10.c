#include "main.h"

/**
 *  print_alphabet_x10 - this func prints 10 time the alphabets in lowercase
 *  Return: returns nothing
*/
void print_alphabet_x10(void)
{
	int i;
	char alphabet;

	for (i = 1; i <= 10; i++)
	{
		for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
			_putchar(alphabet);
		_putchar('\n');
	}
}
