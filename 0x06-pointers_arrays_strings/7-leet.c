#include "main.h"

/**
 * leet - check the code
 *
 * @n: input
 *
 * Return: char val
 */
char *leet(char *n)
{
	int i = 0;
	int j;
	int k;

	char ch1[] = "aAeEoOtTlL";
	char ch2[] = "4433007711";

	while (n[i] != '\0')
	{
		j = 0;
		k = 0;

		while (ch1[j] != '\0')
		{
			if (n[i] == ch1[j])
			{
				k = j;
				n[i] = ch2[k];
			}
			j++;
		}
		i++;
	}

	return (n);
}
