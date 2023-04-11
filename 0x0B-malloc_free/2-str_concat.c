#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	size_t len1, len2;
	char *ans;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	ans = (char *)malloc((len1 + len2 + 1) * sizeof(char));

	if (ans == NULL)
	{
		return (NULL);
	}

	strcpy(ans, s1);
	strcat(ans, s2);
	return (ans);
}
