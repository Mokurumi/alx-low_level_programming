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
int k;
int m;

for (i = '0'; i <= '9'; i++)
{
for (j = '0'; j <= '9'; j++)
{
for (k = i; k <= '9'; k++)
{
for (m = j; m <= '9'; m++)
{
putchar(i);
putchar(j);
putchar(' ');
putchar(k);
putchar(m);

if (j == '8' && m == '9')
continue;

putchar(',');
putchar(' ');
}
}
}
}

putchar('\n');

/* your code goes there */
return (0);
}
