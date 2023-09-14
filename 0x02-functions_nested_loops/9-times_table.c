#include "main.h"
#include <stdio.h>

/**
 * times_table - a func that prints 9 times table
 * starting from 0.
 * Return: returns nothing.
*/
void times_table(void)
{
	int i, j, ans;

	for (i = 0; i <  10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			ans = i * j;
			if (j == 0)
				printf("%d, ", ans);
			else
			{
				printf("%2d", ans);
				if (j != 9)
					printf(", ");
			}
		}
		printf("\n");
	}

}

