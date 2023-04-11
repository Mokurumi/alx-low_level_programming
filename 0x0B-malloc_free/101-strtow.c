#include <stdlib.h>
#include <string.h>

/**
 * count_words - counts the number of words in a string
 *
 * @str: the string to count words in
 *
 * Return: the number of words in the string
 */
int count_words(char *str)
{
	int count = 0, i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return (count);
}

/**
 * free_words - frees the memory allocated for the words array
 *
 * @words: the words array to free
 */
void free_words(char **words)
{
	int i;

	for (i = 0; words[i]; i++)
		free(words[i]);

	free(words);
}

/**
 * strtow - splits a string into words
 *
 * @str: the string to split
 *
 * Return: pointer to an array of strings (words) or NULL if it fails
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);

	count = count_words(str);
	words = malloc(sizeof(char *) * (count + 1));

	if (words == NULL)
		return (NULL);

	i = 0;
	while (str[i] == ' ')
		i++;

	for (k = 0; k < count; k++)
	{
		len = 0;
		for (j = i; str[j] && str[j] != ' '; j++)
			len++;

		words[k] = malloc(sizeof(char) * (len + 1));
		if (words[k] == NULL)
		{
			free_words(words);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[k][j] = str[i + j];

		words[k][j] = '\0';
		i += len + 1;

		while (str[i] == ' ')
			i++;
	}
	words[k] = NULL;
	return (words);
}
