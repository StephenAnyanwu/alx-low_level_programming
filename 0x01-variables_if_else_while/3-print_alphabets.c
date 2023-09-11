#include <stdio.h>

/**
 * main - the main function
 * Return: returns 0 is successful
*/
int main(void)
{
	char j;

	for (j = 'a'; j <= 'z'; j++)
		putchar(j);
	for (j = 'A'; j <= 'Z'; j++)
		putchar(j);
	putchar('\n');
	return (0);
}
