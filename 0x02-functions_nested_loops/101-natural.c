#include "main.h"

/**
 * main - Prints putchar
 *
 * Return: always 0
 *
 */

void main(void)
{

int i;
int sum;

sum = 0;

for (i = 0; i < 1024; i++)
{
if ((i % 3 == 0) || (i % 5 == 0))
sum += i;
}

printf("%d\n", sum);

}
