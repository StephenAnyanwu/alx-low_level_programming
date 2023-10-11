#ifndef MAIN_H
#define MAIN_H
/**
 * struct dog - dog structure.
 * @name: first nember
 * @age: second member.
 * @owner: third member
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner);


#endif
