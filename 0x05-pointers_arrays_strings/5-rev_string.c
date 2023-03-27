#include "main.h"

/**
 * rev_string - check the code
 *
 * @str: input
 *
 */
void rev_string(char *str)
{
	int i;
	int n = strlen(str);

	for (i = (n - 1); i >= 0; i--)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
