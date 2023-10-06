#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - a program that prints the minimum number
 * of coins to make change for an amount of money.
 * @argc: argument counter.
 * @argv: argument vector.
 * Return: returns 0 on success, else returns 1.
*/
int main(int argc, char *argv[])
{
	int unique_coins[] = {25, 10, 5, 2, 1};
	int num = atoi(argv[1]);
	int val = atoi(argv[1]);
	int cents = 0, coins = 0, i;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	while (1)
	{
		if (cents == num)
		{
			printf("%d\n", coins);
			break;
		}
		for (i = 0; i < 5; i++)
		{
			if (val >= unique_coins[i])
			{
				cents += unique_coins[i];
				val -= unique_coins[i];
				coins++;
				i += 4;
			}
		}
	}
	return (0);
}
