#include "main.h"
#include <stdio.h>

/**
 * print_number - prints an integer
 * @n: parameter.
*/
void print_number(int n)
{
	int temp = 0, place_val = 1, m = n;

	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	while (temp != n)
	{
		int i = m;
		int place_val = 1;

		while (i > 9)
		{
			i = i / 10;
			place_val = place_val * 10;			
		}
		putchar(i + '0');
		temp = temp + (place_val * i);
		m = m % place_val;
		i = m;
		place_val = 1;

	}
	putchar('\n');
}

void main(void)
{
	print_number(98);
    putchar('\n');
    print_number(402);
    putchar('\n');
    print_number(1024);
    putchar('\n');
    print_number(0);
    putchar('\n');
    print_number(-98);
    putchar('\n');
}
