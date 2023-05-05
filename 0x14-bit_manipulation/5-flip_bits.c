#include "main.h"

/**
 * flip_bits - returns the # of bits to flip
 *		to get from one number to another
 *
 * @n: first unsigned long int number
 * @m: second unsigned long int number
 *
 * Return: the number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	while (diff != 0)
	{
		if ((diff & 1) == 1)
			count++;
		diff >>= 1;
	}

	return (count);
}
