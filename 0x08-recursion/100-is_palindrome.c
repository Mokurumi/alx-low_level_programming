#include "main.h"

/**
 * is_palindrome - check the code
 *
 * @n: input
 *
 * Return: int
 */
int is_palindrome(char *s)
{
	int len = strlen(s);

	if (len <= 1)
		return (1);
	else
		return (pali_helper(s, 0, len - 1));
}

/**
 * pali_helper - check the code
 *
 * @s: input
 * @start: input
 * @end: input
 *
 * Return: int
 */
int pali_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	else if (s[start] != s[end])
		return (0);
	else
		return (pali_helper(s, start + 1, end - 1));
}
