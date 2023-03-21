#include "main.h"

/**
 * print_to_98 - Prints putchar
 *
 * @n: input
 *
 * Return: always 0
 */

void print_to_98(int n)
{

if (n == 98)
{
printf("%d, ", n);
return (0);
}

while (n <= 98)
{

printf("%d, ", n);

n++;
}

while (n >= 98)
{
printf("%d, ", n);
n--;
}

printf("\n");

}
