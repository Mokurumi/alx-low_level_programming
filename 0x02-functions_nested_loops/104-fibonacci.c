#include <stdio.h>

/**
 * main - Prints putchar
 *
 * Return: always 0
 *
 */
int main()
{
int a = 1, b = 2, next, i;

printf("%d, %d", a, b);

for (i = 2; i < 98; i++)
{
next = a + b;
printf(", %d", next);
a = b;
b = next;
}

printf("\n");

return (0);
}
