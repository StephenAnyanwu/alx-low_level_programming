#include <stdio.h>

/**
 * main - the main function
 * Return: return 0 if successful
*/
int main(void)
{
	int i;
	char j;

	for (i = 0; i <= 9; i++)
		putchar(i + '0');
	for (j = 'a'; j <= 'f'; j++)
		putchar(j);
	putchar('\n');
	return (0);

}
