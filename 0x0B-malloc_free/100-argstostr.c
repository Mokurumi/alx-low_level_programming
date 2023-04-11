#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program
 *
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: pointer to a new string containing the concatenated arguments
 * or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k, len;

	if (ac == 0 || av == NULL)
		return (NULL);

	len = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;

		len++; /* account for space or newline character */
	}

	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (NULL);

	k = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			str[k] = av[i][j];
			k++;
		}

		str[k] = '\n';
		k++;
	}

	str[k] = '\0';

	return (str);
}
