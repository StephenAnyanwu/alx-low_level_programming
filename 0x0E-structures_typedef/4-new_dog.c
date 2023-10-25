#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * new_dog - a function that create a new dog.
 * @name: new dog's name.
 * @age: new dog's age.
 * @owner: new dog's owner.
 * Note, the arguments name and owner is being copied instead of assigned.
 * Return: returns a pointer to the new dog created.
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int n1, o1, i;
	dog_t *dog;

	if (name == NULL || owner == NULL)
		return (NULL);
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);
	for (n1 = 0; name[n1]; n1++)
		;
	n1++;
	dog->name = malloc(sizeof(char) * n1);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}
	for (i = 0; i < n1; i++)
		dog->name[i] = name[i];
	dog->age = age;
	for (o1 = 0; owner[o1]; o1++)
		;
	o1++;
	dog->owner = malloc(sizeof(char) * o1);
	if (dog->owner == NULL)
	{
		free(dog->owner);
		free(dog);
		return (NULL);
	}
	for (i = 0; i < o1; i++)
		dog->owner[i] = owner[i];
	return (dog);
}
