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

printf("%d", first);

for (i = 1; i < n; i++)
{
printf(", %d", second);
next = first + second;
first = second;
second = next;
}

printf("\n");

return (0);

}
