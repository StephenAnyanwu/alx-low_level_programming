#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - The main function.
 * Return: returns 0 if successful.
*/
int main(void)
{
	int n;
	int m;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	m = n % 10;
	if (m > 5)
		printf("The last digit of %d is %d and is greater than 5", n, m);
	if (m == 0)
		printf("The last digit of %d is %d and is 0", n, m);
	if (m < 6 && m != 0)
		printf("The last digit of %d is %d and is less than 6 and not 0", n, m);
	printf("\n");

	return (0);
}
