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
	char *name_copy, *owner_copy;

	d = malloc(sizeof(struct dog));
	if (d == NULL)
	{
		return (NULL);
	}

	name_copy = malloc(strlen(name) + 1);
	if (name_copy == NULL)
	{
		free(d);
		return (NULL);
	}

	strcpy(name_copy, name);

	owner_copy = malloc(strlen(owner) + 1);
	if (owner_copy == NULL)
	{
		free(name_copy);
		free(d);
		return (NULL);
	}

	strcpy(owner_copy, owner);

	d->name = name_copy;
	d->age = age;
	d->owner = owner_copy;

	return (d);
}
