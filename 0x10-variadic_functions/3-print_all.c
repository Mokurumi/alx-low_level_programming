#include "variadic_functions.h"

/**
 * print_all - print everything
 *
 * @format: args format
 *
 * Return: nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i;
	char *s;

	va_start(args, format);
	i = 0;

	/* Loop through the format string and print the corresponding argument */
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", (float)va_arg(args, double));
				break;
			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					printf("(nil)");
				else
					printf("%s", s);

				break;
		}

		i++;
		/* Print the separator character if there are more arguments */
		if (format[i] != '\0' && (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
			printf(", ");
	}
	va_end(args);
	/* Print a new line at the end */
	printf("\n");
}
