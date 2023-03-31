#include "main.h"

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
			if (s[i] == data1[j])
			{
				s[i] = datarot[j];
				break;
			}
		}
	}

	return (s);
}
