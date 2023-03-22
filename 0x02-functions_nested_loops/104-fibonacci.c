#include <stdio.h>

/**
 * main - main function
 *
 * Return: always 0
 */
int main(void)
{

long a = 1, b = 2, c, i;
printf("%ld, %ld, ", a, b);

for(i = 3; i <= 98; i++) {
c = a + b;
printf("%ld", c);
if(i < 98) printf(", ");
a = b;
b = c;
}

printf("\n");

return (0);
}
