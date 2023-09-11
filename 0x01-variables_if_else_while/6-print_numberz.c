#include <stdio.h>

/**
 * main - the main function
 * Return: Return 0 is successful
*/
int main(void)
{
	int digit;

	for (digit = 0; digit < 10; digit++)
		putchar(digit + '0');
	putchar('\n');
	return (0);
}
