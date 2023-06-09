#include <stdlib.h>

/**
 * array_range - creates an array of integers from min to max.
 *
 * @min: minimum value.
 * @max: maximum value.
 *
 * Return: pointer to the newly created array.
 *         NULL if failure or min > max.
 */
int *array_range(int min, int max)
{
	int *arr, i, size;

	if (min > max)
		return (NULL);

	size = (max - min) + 1;
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min++;

	return (arr);
}
