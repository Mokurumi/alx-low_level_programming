#include "main.h"

/**
 * is_prime_number - check the code
 *
 * @n: input
 *
 * Return: int
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else
		return (prime_helper(n, 2));
}

/**
 * prime_helper - check the code
 *
 * @n: input
 * @i: input
 *
 * Return: int
 */
int prime_helper(int n, int i)
{
	/* if i is greater than the square root of n, n is prime */
	if (i * i > n)
	{
		return (1);
	}
	/* if n is divisible by i, n is not prime */
	else if (n % i == 0)
	{
		return (0);
	}
	/* do recursion */
	else
	{
		return (prime_helper(n, i + 1));
	}
}
