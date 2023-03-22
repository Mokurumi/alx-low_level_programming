#include <stdio.h>

/**
 * main - main function
 * 
 * Return: always 0
 */

int main(void)
{

long first = 1, second = 2, next, i;

printf("%ld, %ld", first, second);

for (i = 3; i <= 50; i++)
{
next = first + second;
printf(", %ld", next);
first = second;
second = next;
}

printf("\n");

return (0);

}
