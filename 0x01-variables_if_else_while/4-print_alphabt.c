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
char i;

for (i = 'a'; i <= 'z'; i++)
{
if (i != 'e' && i != 'q')
{
putchar(i);
}
}
putchar('\n');

/* your code goes there */
return (0);
}
