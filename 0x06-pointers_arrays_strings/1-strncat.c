#include "main.h"

/**
 * _strncat - check the code
 *
 * @dest: input
 * @src: input
 * @n: input
 *
 * Return: char output
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = _strlen(dest);
	int j = 0;

	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
