#include "main.h"

/**
 * rev_string - check the code
 *
 * @s: input
 *
 */
void rev_string(char *s)
{
	int i;
	int n = strlen(s);

	for (i = 0; i < n / 2; i++)
	{
		tmp = s[i];
		s[i] = s[n - 1 - i];
		s[n - 1 - i] = tmp;
	}
}
