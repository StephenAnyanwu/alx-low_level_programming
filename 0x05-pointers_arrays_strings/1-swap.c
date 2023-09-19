#include "main.h"

/**
 * swap_int - a function that swaps the values of two integers.
 * @a: first integer (parameter).
 * @b: second integer (parameter).
*/
void swap_int(int *a, int *b)
{
	int i = *a, j = *b;

	*a = j;
	*b = i;
}
