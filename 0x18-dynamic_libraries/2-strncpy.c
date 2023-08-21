#include "main.h"

/**
 * _strncpy - check the code
 *
 * @dest: input
 * @src: input
 * @n: input
 *
 * Return: char output
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)

	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
