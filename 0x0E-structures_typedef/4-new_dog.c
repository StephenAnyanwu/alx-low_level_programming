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
	int name_len = 0, owner_len = 0, i;
	dog_t *newDog;

	if (name == NULL || owner == NULL)
		return (NULL);
	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
	{
		free(newDog);
		return (NULL);
	}
	/* length of name including \0 char */
	while (name[name_len] != '\0')
		name_len++;
	name_len++;
	/* length of owner including \0 char */
	while (owner[owner_len] != '\0')
		owner_len++;
	owner_len++;
	newDog->name = malloc(sizeof(char) * name_len);
	if (newDog->name == NULL)
	{
		free(newDog);
		return (NULL);
	}
	for (i = 0; i < name_len; i++)
		newDog->name[i] = name[i];
	newDog->owner = malloc(sizeof(char) * owner_len);
	if (newDog->owner == NULL)
	{
		free(newDog);
		return (NULL);
	}
	for (i = 0; i < owner_len; i++)
		newDog->owner[i] = owner[i];
	newDog->age = age;
	return (newDog);
}
