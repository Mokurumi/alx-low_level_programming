#include "main.h"

/**
 * _sqrt_recursion - check the code
 *
 * @n: input
 *
 * Return: int
 */
int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	else
		return (_sqrt_helper(n, 1));
}

/**
 * _sqrt_helper - check the code
 *
 * @n: input
 * @start: input
 *
 * Return: the square root of n or -1 if n does not have a natural square root.
 */
int _sqrt_helper(int n, int start)
{
	/* exhausted search */
	if (start * start > n)
		return (-1);
	/* square root found */
	else if (start * start == n)
		return (start);
	/* increase the number and check again  */
	else
		return (_sqrt_helper(n, start + 1));
}
