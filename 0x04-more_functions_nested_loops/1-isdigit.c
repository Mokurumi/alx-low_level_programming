#include "main.h"
/* more headers goes there */

/**
 * _isdigit - Entry point
 *
 * @c: param
 *
 * Return: Always 0
 */

int _isdigit(int c)
{

	if (c >= 48 && c <= 57)
	{
		return (1);
	}

	return (0);
}
