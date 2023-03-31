#include <stdio.h>
#include <string.h>

/**
 * rot13 - check the code
 *
 * @n: input
 *
 * Return: char val
 */
char *rot13(char *n)
{
	int i, j;
	char albet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char betal[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; i < strlen(n); i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (n[i] == albet[j])
			{
				n[i] = betal[j];
				break;
			}
		}
	}

	return (n);
}
