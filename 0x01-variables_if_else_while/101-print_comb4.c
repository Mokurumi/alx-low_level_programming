#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* more headers goes there */

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{

int i;
int j;
nt k;

for (i = '0'; i <= '9'; i++)
{
for (j = i + 1; j <= '9'; j++)
{
for (k = j + 1; k <= '9'; k++)
{
if (i != j)
{
putchar(i);
putchar(j);
putchar(k);
}

if (i == '7')
continue;

putchar(',');
putchar(' ');
}
}
}

putchar('\n');

/* your code goes there */
return (0);
}
