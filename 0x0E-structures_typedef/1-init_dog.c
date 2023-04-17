#include "dog.h"

/**
 * init_dog - initialize dog
 *
 * @d: struct to initialize
 * @name: val 1
 * @age: val 2
 * @owner: val 3
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
