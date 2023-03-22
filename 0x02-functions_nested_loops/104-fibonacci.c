#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0
 */
int main(void)
{

unsigned int i;
unsigned long int j = 1, k = 2, temp;

printf("%lu, %lu", j, k);
for (i = 3; i <= 98; i++)
{
printf(", %lu", j + k);
temp = j;
j = k;
k += temp;
}

printf("\n");

return (0);
}
