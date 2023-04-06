#include "main.h"

/**
 * wildcmp - check the code
 *
 * @s1: input
 * @s2: input
 *
 * Return: int
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_helper(s1, s2));
}

/**
 * wildcmp_helper - check the code
 *
 * @s1: input
 * @s2: input
 *
 * Return: int
 */
int wildcmp_helper(char *s1, char *s2)
{
	int res;

	/* If the strings are identical or s2 is empty and s1 is not */
	if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (1);
		else
			return (wildcmp_helper(s1 + 1, s2 + 1));
	}
	/* If s2 contains the special character * */
	else if (*s2 == '*')
	{
		/* If the next character in s2 is also *, skip it */
		if (*(s2 + 1) == '*')
			return (wildcmp_helper(s1, s2 + 1));

		/* Check all possible combinations of s1 and s2 after the * */
		res = wildcmp_helper(s1, s2 + 1);

		if (!res && *s1 != '\0')
			res = wildcmp_helper(s1 + 1, s2);

		return (res);
	}
	/* If the chars do not match and s2 doesn't contain the special char * */
	else
		return (0);
}
