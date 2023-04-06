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
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);

	return (_sqrt_helper(n, 1, n));
}

/**
 * _sqrt_helper - check the code
 *
 * @n: input
 * @start: input
 * @end: input
 *
 * Return: the square root of n or -1 if n does not have a natural square root.
 */
int _sqrt_helper(int n, int start, int end)
{
	int mid;

	/* check for perfect square */
	if (start == end && start * start == n)
		return (start);

	/* exhausted search range */
	if (start > end)
		return (-1);

	mid = start + (end - start) / 2;

	/* mid point is the square root */
	if (mid * mid == n)
		return (mid);
	/* if mid is too high, search starting half */
	else if (mid * mid > n)
		return (_sqrt_helper(n, start, mid - 1));
	/* else search last half */
	else
		return (_sqrt_helper(n, mid + 1, end));
}
