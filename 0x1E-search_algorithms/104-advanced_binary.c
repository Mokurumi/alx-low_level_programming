#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Search for a value in a sorted array of integers
 * using Advanced Binary search algorithm in a recursive way
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the first occurrence of the value is located,
 * or -1 if not found or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid = (size - 1) / 2;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
		printf("%d%s", array[i], i == size - 1 ? "\n" : ", ");

	if (array[mid] == value && (mid == 0 || array[mid - 1] != value))
		return (mid);
	else if (size == 1)
		return (-1);

	if (array[mid] < value)
		return (advanced_binary(array + mid + 1, size - mid - 1, value) + mid + 1);
	else
		return (advanced_binary(array, mid + 1, value));
}
