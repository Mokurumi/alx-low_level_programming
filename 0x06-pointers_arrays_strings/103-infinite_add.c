#include <string.h>

/**
 * infinite_add - check the code
 *
 * @n1: input
 * @n2: input
 * @r: input
 * @size_r: input
 *
 * Return: char val
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int carry = 0;
	int sum, i, j;


	if (len1 + len2 + 1 > size_r)
	{
		return 0;
	}

	for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--)
	{
		sum = carry;
		if (i >= 0)
		{
			sum += n1[i] - '0';
		}

		if (j >= 0)
		{
			sum += n2[j] - '0';
		}

		carry = sum / 10;
		sum %= 10;
		r[len1 + len2 - i - j - 2] = sum + '0';
	}
	r[len1 + len2 - i - j - 2] = '\0';
	for (i = 0, j = len1 + len2 - 2; i < j; i++, j--)
	{
		char temp = r[i];
		r[i] = r[j];
		r[j] = temp;
	}
	return r;
}
