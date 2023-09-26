#include "main.h"

/**
 * print_diagsums - a function that prints the sum
 *of the two diagonals of a square matrix of integers.
 *@a: array.
 *@size: array size (2D);
 *Return:void.
*/
void print_diagsums(int *a, int size)
{
	int x, sum1 = 0, sum2 = 0;

	for (x = 0; x < size; x++)
		sum1 = sum1 + a[x * size + x];
	for (x = size - 1; x >= 0; x--)
		sum2 = sum2 + a[x * size + (size - x - 1)];
	printf("%d, %d\n", sum1, sum2);

}
