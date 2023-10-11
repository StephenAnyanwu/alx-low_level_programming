#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_dog - a function that prints struct dog members.
 * @d: a pointer to a struct dog variable that it smember is to be
 * printed.
*/
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		if ((*d).name == NULL)
			printf("Name: (nil)");
		else if ((*d).age == 0 || (*d).owner == NULL)
			printf("(nil)");
		else
		{
			printf("Name: %s\n", (*d).name);
			printf("Age: %f\n", (*d).age);
			printf("Owner: %s\n", (*d).owner);
		}
	}
}
