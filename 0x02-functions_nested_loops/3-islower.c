#include "main.h"
/* more headers goes there */

/**
 * _islower - Entry point
 *
 * @c: param
 *
 * Return: Always 0
 */

int _islower(int c)
{

if (c >= 97 && c <= 122)
{
return (1);
}
else
{
return (0);
}
}
