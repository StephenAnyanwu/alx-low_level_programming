#include <stdio.h>

/**
 * main - a function that computes and prints the sum of
 * all multiples of 3 or 5 below 1024.
 * Return: returns 0 if successful.
*/
int main(void)
{
	int n = 1024;
	int _sum = 0;
	int i;

	printf("multiples of 3 or 5 below %d:\n", n);
	for (i = 3; i < n; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			if (i == n - (n % 3))
				printf("%d", i);
			else
				printf("%d, ", i);
			_sum += i;
		}
	}
	printf("\n");
	printf("\nThe sum of all the multiples of 3 or 5 below %d: %d\n", n, _sum);
	return (0);
}
