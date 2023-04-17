#include "dog.h"

/**
 * fre_dog - clean memory
 *
 * @d: dog input
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->owner);
		free(d->age);
		free(d->name);
	}
}
