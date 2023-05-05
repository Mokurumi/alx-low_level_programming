#include "main.h"

/**
 * get_endianness - checks the endianness of the system
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *p = (char *)&x;

	if (*p == 1)
		/* least significant byte is stored first */
		return (1); /* little endian */
	else
		return (0); /* big endian */
}
