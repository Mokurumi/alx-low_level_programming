#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Helper function for advanced binary search
 * @array: Pointer to the first element of the sorted array to search in
 * @left: Left index of the array for searching
 * @right: Right index of the array for searching
 * @value: The value to search for
 *
 * Return: The index where the first occurrence of the value is located,
 * or -1 if not found
 */
int advanced_binary_recursive(int *array, int left, int right, int value)
{
	int i, mid;

	if (left > right)
		return (-1);

	mid = left + (right - left) / 2;

	printf("Searching in array: ");
	for (i = left; i <= right; ++i)
		printf("%d%s", array[i], (i == right) ? "\n" : ", ");

	if (array[mid] == value)
		if (mid == left || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary_recursive(array, left, mid - 1, value));
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, right, value));
	else
		return (advanced_binary_recursive(array, left, mid - 1, value));
}

/**
 * advanced_binary - Search for a value in a sorted array of integers
 * using Advanced Binary search algorithm
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the first occurrence of the value is located,
 * or -1 if not found or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value) {
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
