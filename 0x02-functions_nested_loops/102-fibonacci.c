#include <stdio.h>

/**
 * main - main function
 *  
 * Return: always 0
 */

int main(void)
{

long long first = 1, second = 2, next, i;

printf("%lld, %lld", first, second);

for (i = 3; i <= 50; i++)
{
next = first + second;
printf(", %lld", next);
first = second;
second = next;
}

printf("\n");

return (0);

}
