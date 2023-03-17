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
int n;

srand(time(0));
n = rand() - RAND_MAX / 2;

char charr;

for (charr = 'a'; charr <= 'z'; charr++)
{
putchar(charr);
putchar('\n');
}

/* your code goes there */
return (0);
}
