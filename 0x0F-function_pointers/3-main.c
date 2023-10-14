#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - performs calculation on the command line.
 * @argc: argument counter.
 * @argv: argument vector.
 * Return: result calculated.
*/
int main(int argc, char *argv[])
{
	/* opearator to be inputted */
	char *op;
	/* integers to be inputted */
	int num1, num2;
	
	/* func_name num1 op num2 are the expected args */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);
	/* if op not in operator list or op is more than one char */
	if (get_op_func(op) == NULL || op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}
	/* if the user tries to divide (/ or %) by 0 */
	if ((num2 == 0 && *op == '/') || (num2 == 0 && *op == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	/* print operation result */
	printf("%d\n", get_op_func(op)(num1, num2));
	return (0);
}
