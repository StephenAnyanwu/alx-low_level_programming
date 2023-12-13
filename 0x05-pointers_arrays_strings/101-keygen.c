#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - a program that generates random valid
 * passwords for the program 101-crackme.
 * Return: always 0 (success).
*/
int main(void)
{
	int pwd[100];
	int sum = 0, i, n;
	/* time in seconds since the Epoch (00:00:00 UTC, January 1, 1970) */
	time_t seconds = time(NULL); /* time_t aka {long int} */

	/* initializes random number generator (i.e seed) */
	srand(seconds);

	for (i = 0; i < 100; i++)
	{
		pwd[i] = rand() % 78; /* random number from 0 to 78 */
		sum += (pwd[i] + '0');
		putchar(pwd[i] + '0');
		if ((2772 - sum) - '0' < 78)
		{
			n = 2772 - sum - '0';
			sum += n;
			putchar(n + '0');
			break;
		}
	}
	return (0);
}
