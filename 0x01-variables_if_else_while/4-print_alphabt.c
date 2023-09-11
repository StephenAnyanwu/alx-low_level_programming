#include <stdio.h>

/**
 * main - the main function
 * Return: return 0 if succesful
*/
int main(void)
{
	char alphabet;

	for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
		if (alphabet != 'e' &&  alphabet != 'q')
			putchar(alphabet);
	putchar('\n');
	return (0);
}
