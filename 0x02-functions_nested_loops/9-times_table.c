#include "main.h"

/**
 * times_table - Prints putchar
 */

void times_table(void)
{

int i;
int j;
int p;

for (i = 0; i < 10; i++)
{
for (j = 0; j < 10; j++)
{

p = i * j;

if (j != 0)
{
_putchar(',');

if (p < 10)
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
