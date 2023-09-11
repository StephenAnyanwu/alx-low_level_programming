#include <stdio.h>

/**
 * main - the main function
 * Return: returns 0 if sucessful
*/
int main(void)
{
	int n;
	int m;

	for (n = 48; n <= 56; n++)
	{
		for (m = 49; m <= 57; m++)
		{
			if (m > n)
			{
				putchar (n);
				putchar (m);
				if (n != 56 || m != 57)
				{
					putchar (',');
					putchar (' ');
				}
			}
		}
	}
	putchar ('\n');
	return (0);
}
