#include "main.h"

/**
 * cap_string - check the code
 *
 * @n: input
 *
 * Return: char val
 */
char *cap_string(char *n)
{
	int i = 0;

	while (n[i] != '\0')
	{
		if ((n[i - 1] == ' ' || n[i - 1] == '\n'
					|| n[i - 1] == '\t' || n[i - 1] == ','
					|| n[i - 1] == ';' || n[i - 1] == '!'
					|| n[i - 1] == '?' || n[i - 1] == '"'
					|| n[i - 1] == '(' || n[i - 1] == ')'
					|| n[i - 1] == '{' || n[i - 1] == '}'
					|| n[i - 1] == '.')
				&& (n[i] >= 'a' && n[i] <= 'z'))
		{
			n[i] = n[i] - 32;
		}
		else if (i == 0 && n[i] >= 'a' && n[i] <= 'z')
		{
			n[i] = n[i] - 32;
		}
		else
		{
			n[i] = n[i];
		}

		i++;
	}

	return (n);
}
