#include "main.h"

/**
 * print_array - check the code
 *
 * @a: input
 * @n: input
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i > 0)
			printf(", ");

		printf("%d", a[i]);
	}

	printf("\n");
}
