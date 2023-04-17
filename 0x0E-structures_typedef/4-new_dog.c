#include "dog.h"

/**
 * new_dog - create new dog
 *
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 *
 * Return: Always 0.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *d;

	d = malloc(sizeof(struct dog));

	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;

		return (d);
	}

	return (NULL);
}
