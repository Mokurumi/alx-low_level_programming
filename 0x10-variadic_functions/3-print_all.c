#include "variadic_functions.h"

/**
 * print_all - print everything
 *
 * @format: args format
 *
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *s;
	int i = 0, printed;
	int separator = 0;

	va_start(args, format);
	if (format == NULL || format == '\0')
		return;
	/* Loop through format string and print corresponding argument */
	while (format[i] != '\0')
	{
		printed = 0; /* Flag for if an argument has been printed */
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				printed = 1;
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				printed = 1;
				break;
			case 'f':
				printf("%f", (float)va_arg(args, double));
				printed = 1;
				break;
			case 's':
				s = va_arg(args, char *);
				printf("%s", s == NULL ? "(nil)" : s);
				printed = 1;
				break;
		}
		/* Print the separator if necessary */
		separator = (printed && format[i + 1] != '\0') ? 1 : 0;
		printf("%s", separator ? va_arg(args, char *) : "");
		i++;
	}
	va_end(args);
	printf("\n");
}
