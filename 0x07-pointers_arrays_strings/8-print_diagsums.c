#include "main.h"

/**
 * print_diagsums - check the code
 *
 * @a: input
 * @size: input
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		/* add diagonal element */
		sum1 += *(a + i*size + i);
		/* add anti-diagonal element */
		sum2 += *(a + i*size + size - 1 - i);
	}

	printf("%d, %d\n", sum1, sum2);
}
