#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - a function to free memory of dog.
 * @d: a pointer to dog_t (alias of struct dog) datatype,
 * memory to be freed.
*/
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
