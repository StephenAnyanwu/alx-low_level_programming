#include <stdio.h>

/**
 * main - the main function
 * Return: returns 0 if successful
*/
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		if (num == 9)
			putchar(num + '0');
		else
		{
			putchar(num + '0');
			putchar(',');
			putchar(' ');
		}
	}
	return (0);
}
