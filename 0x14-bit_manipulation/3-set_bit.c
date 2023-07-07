#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 *
 * @n: pointer to an unsigned long int number
 * @index: index, starting from 0
 *
 * Return: 1 for success, or -1 for an error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1); /* index out of range */

	*n |= (1 << index); /* set bit at index to 1 */

	return (1);
}
