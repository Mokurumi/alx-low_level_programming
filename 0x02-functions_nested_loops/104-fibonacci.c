#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0
 */
int main(void)
{
int first = 1, second = 2, next;

printf("%d, %d", first, second);

for (int i = 3; i <= 98; i++) {
next = first + second;
printf(", %d", next);
first = second;
second = next;
}

printf("\n");

printf("\n");
return (0);
}
