#include <stdlib.h>

/**
 * create_array - creates char array and initializes it with a specific char
 *
 * @size:  array size
 * @c: character to initialize the array with
 *
 * Return: pointer to created array, or NULL if allocation fails
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0) /* check for size 0 */
	{
		return (NULL);
	}

	/* allocate memory for array */
	arr = malloc(size * sizeof(char));

	if (arr == NULL) /* check for allocation failure */
	{
		return (NULL);
	}

	/* initialize array with specific char */
	for (i = 0; i < size; i++)
	{
		arr[i] = c;
	}

	return (arr); /* return pointer to array */
}
