#include "main.h"
/* more headers goes there */

/**
 * _isupper - Entry point
 *
 * @c: param
 *
 * Return: Always 0
 */

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
