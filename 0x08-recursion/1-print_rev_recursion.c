#include "main.h"

/**
 * _print_rev_recursion - check the code
 *
 * @s: input
 */
void _print_rev_recursion(char *s)
{
	if (*s != '\0')
	{
		/* reversed recursion */
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
