#include <stdio.h>
#include "lists.h"

void __attribute__((constructor)) calledFirst();
/**
 * ComeFirst - a function that runs first bere the main.
*/
void ComeFirst(void)
{
	printf("(A tortoise, having pretty good sense of a hare's nature, ");
	printf("challenges one to a race.)\n");
}
