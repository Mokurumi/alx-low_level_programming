#include "main.h"

/**
 * _strchr - check the code
 *
 * @s: input
 * @c: input
 *
 * Return: char
 *
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	if (c == '\0')
	{
		return (s);
	}

	return (NULL);
}
