#include <stdio.h>

/**
 * main - the main function
 * Return: returns 0 if successful
*/
int main(void)
{
	int i;
	int j;

	for (i = 0; i < 9; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (i != j)
			{
				putchar(i + '0');
				putchar(j + '0');
				putchar(',');
				putchar(' ');
			}
		}




	}
	putchar('\n');
	return (0);
}
