#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 *
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number,
 *	or 0 if there is an invalid char or if b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
		{
			/* Left shift by 1 is equivalent to multiplying by 2 */
			num <<= 1;
		}
		else if (b[i] == '1')
		{
			num <<= 1;
			/* Set the least significant bit to 1 */
			num |= 1;
		}
		else
		{
			/* Invalid character found, return 0 */
			return (0);
		}
	}

	return (num);
}