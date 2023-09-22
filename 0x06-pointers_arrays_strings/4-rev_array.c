#include "main.h"

/**
 * reverse_array - a function that reverses the
 * content of an array.
 * @a: an array.
 * @n: the number of elements of the array.
 * Return: void.
*/
void reverse_array(int *a, int n)
{
	int start = 0, end = n - 1, temp;

	while (start < end)
	{
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}
