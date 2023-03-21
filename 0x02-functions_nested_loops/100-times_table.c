#include "main.h"

/**
 * print_times_table - Prints putchar
 *
 * @n: input
 */

void print_times_table(int n)
{
int i;
int j;
int p;
if (n > -1 && n < 16)
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
{
_putchar('0' + p);
}
else
{
_putchar('0' + (p / 10));
_putchar('0' + (p % 10));
}
}
_putchar('\n');
}
}
