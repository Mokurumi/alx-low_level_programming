#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 *
 * @n: unsigned long int number
 * @index: index, starting from 0, of the bit to retrieve
 *
 * Return: value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1); /* index out of range */

	return ((n >> index) & 1);
}
