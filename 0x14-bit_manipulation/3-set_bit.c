#include "main.h"

/**
 * set_bit -  a function that sets the value of a bit to 1 at a given index.
 * @n: a poniter to decimal to be manipulated.
 * @index: the index, starting from 0 of the bit you want to set.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
*/

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask = 1;

	if (index > sizeof(size_t) * 8)
		return (-1);
	mask = mask << index;
	*n = ((*n) | mask);
	return (1);
}
