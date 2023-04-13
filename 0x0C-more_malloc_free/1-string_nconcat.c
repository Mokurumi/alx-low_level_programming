#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - check the code
 *
 * @s1: original string
 * @s2: string to concatenate
 * @n: length of s2 to concarenate
 *
 * Return: char pointer
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1, len2;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	if (n >= len2)
		n = len2;

	concat = malloc(len1 + n + 1);

	if (concat == NULL)
		return (NULL);

	memcpy(concat, s1, len1);
	memcpy(concat + len1, s2, n);
	concat[len1 + n] = '\0';
	return (concat);
}
