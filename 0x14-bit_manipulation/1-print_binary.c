#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 *
 * @n: the number to print
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		/* Recursively print the binary representation of n/2 */
		print_binary(n >> 1);

	/* Print the rightmost bit of n */
	putchar((n & 1) ? '1' : '0');
}
