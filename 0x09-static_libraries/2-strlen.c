#include "main.h"

/**
 * _strlen - check the code
 *
 * @s: input
 *
 * Return: output
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}

	return length;
}
