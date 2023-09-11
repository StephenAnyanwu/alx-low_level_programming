#include <stdio.h>

/**
 * main - the main function
 * Return: returns 0 if successful
*/
int main(void)
{
	char alphabet;

	for (alphabet = 'z'; alphabet >= 'a'; alphabet--)
		putchar(alphabet);
	putchar('\n');
	return (0);
}
