#include "main.h"
/* more headers goes there */

/**
 * print_alphabet_x10 - Entry point
 */

void print_alphabet_x10(void)
{

char i;
int k;

for (k = 0; k < 10; k++)
{
for (i = 'a'; i <= 'z'; i++)
{
_putchar(i);
}

_putchar('\n');
}
}
