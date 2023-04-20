#include "variadic_functions.h"

/**
 * print_numbers - summ all its parameters
 *
 * @n: number of args
 * @separator: string separator
 *
 * Return: int
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	int num;
	unsigned int i;

	va_start(args, n);

	/* Loop through the arguments and print them, separated by the separator */
	for (i = 0; i < n; i++)
	{
		num = va_arg(args, int);
		printf("%d", num);

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	va_end(args);
	/* Print a new line at the end */
	printf("\n");
}
