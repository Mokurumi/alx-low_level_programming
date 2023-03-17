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

for (i = '0'; i <= '9'; i++)
{
for (j = '0'; j <= '9'; j++)
{
for (k = j + 1; k <= '9'; k++)
{
putchar(i);
putchar(j);
putchar(' ');
putchar(i);
putchar(k);
if (i == '9' && k == '9')
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
