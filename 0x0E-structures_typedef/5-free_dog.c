#include "dog.h"

/**
 * free_dog - clean memory
 *
 * @d: dog input
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
