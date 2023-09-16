#include "main.h"

/**
 * more_numbers - a func that prints 10 times the number
 * from 0 to 14.
 *Return: returns nothing.
*/
void more_numbers(void)
{
	int i;
	int j;
	int mod;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			mod = j % 10;
			if (j > 9)
				_putchar(1 + '0');
			_putchar(mod + '0');
		}
		_putchar('\n');
	}
}
