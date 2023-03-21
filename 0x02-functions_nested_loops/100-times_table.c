#include "main.h"

/**
 * print_times_table - Prints putchar
 *
 * @n: input
 */

void print_times_table(int n)
{
int i = 0;
int j = 0;
int p;

if (n >= 0 && n <= 15)
for (i = 0; i <= n; i++)
{
for (j = 0; j <= n; j++)
{
p = i * j;
if (j != 0)
{
_putchar(',');
if (p < 10)
_putchar(' ');
if (p < 100)
_putchar(' ');

_putchar(' ');
}
if (p < 10)
_putchar('0' + p);
else if (p > 9 && p < 100)
{
_putchar('0' + (p / 10));
_putchar('0' + (p % 10));
}
else
{
_putchar('0' + (p / 100));
_putchar('0' + (p / 10));
_putchar('0' + (p % 10));
}
}
_putchar('\n');
}
}
