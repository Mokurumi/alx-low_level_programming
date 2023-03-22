#include <stdio.h>

/**
 * main - main function
 *  
 * Return: always 0
 */

int main(void)
{
      
int n = 50;
int first = 1;
int second = 2;
int next;
int i;

printf("%d, %d, ", first, second);

for (i = 2; i < n; i++)
{
next = first + second;
printf("%d", next);

if (i != n - 1)
{
printf(", ");
}

first = second;
second = next;
}

printf("\n");

return 0;

}
