#include "main.h"
#include <stdio.h>


/**
 * main - a func that print from 1 to 100
 * Return: returns 0
*/
int  main(void)
{
	int n = 100;
	int i;
	char f[] = "Fizz";
	char b[] = "Buzz";
	char fb[] = "FizzBuzz";

	for (i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
			printf("%s", f);
		else if (i % 5 == 0)
			printf("%s", b);
		else if (i % 8 == 0)
			printf("%s", fb);
		else
			printf("%d", i);
		printf("%c", ' ');
	}
	printf("\n");
	return (0);
}
