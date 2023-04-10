#include "main.h"

/**
 * _memset - check the code
 *
 * @s: input
 * @b: input
 * @n: input
 *
 * Return: char
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
