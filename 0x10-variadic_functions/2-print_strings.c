#include "variadic_functions.h"

/**
 * print_strings- summ all its parameters
 *
 * @n: number of args
 * @separator: string separator
 *
 * Return: int
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	/* Loop through the arguments and print them, separated by the separator */
	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", str);
		}

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	va_end(args);
	/* Print a new line at the end */
	printf("\n");
}
