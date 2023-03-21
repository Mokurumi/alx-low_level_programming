#include "main.h"
/* more headers goes there */

/**
 * print_last_digit - Entry point
 *
 * @n: param
 *
 * Return: Always 0
 */

int print_last_digit(int n)
{

int i = n % 10;

if (i < 0)
i *= -1;

_putchar(i + '0');

return (i);
}
