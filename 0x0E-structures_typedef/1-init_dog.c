#include "dog.h"

/**
 * init_dog - a function that initialize a variable of type struct dog.
 * @d: a pointer to a declared variable of type struct dog to be initialized.
 * @name: first nember of d (string literal).
 * @age: second member of d (int).
 * @owner: third member of d (string literal).
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
