#include <stdlib.h>

/**
 * malloc_checked - malloc memory allocation
 *
 * @b: the size of the memory to print
 *
 * Return: pointer
 *
 */
void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (!p)
		exit(98);

	return (p);
}
