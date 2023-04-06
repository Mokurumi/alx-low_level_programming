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
	return wildcmp_helper(s1, s2);
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
	/* If the strings are identical or s2 is empty and s1 is not */
	if (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 1;
		else
			return wildcmp_helper(s1+1, s2+1);
	}
	/* If s2 contains the special character * */
	else if (*s2 == '*')
	{
		/* If the next character in s2 is also *, skip it */
		while (*(s2+1) == '*')
			s2++;
		/* Check all possible combinations of s1 and s2 after the * */
		while (*s1 != '\0')
		{
			if (wildcmp_helper(s1, s2+1))
				return 1;
			s1++;
		}
		/* If no match is found */
		return 0;
	}
	/* If the chars do not match and s2 doesn't contain the special char * */
	else
		return 0;
}
