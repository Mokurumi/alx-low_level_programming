#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array of integers
 * using binary search algorithm
 *
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located,
 * or -1 if not found or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t i, low, high;

	if (array == NULL)
		return (-1);

	for (low = 0, high = size - 1; high >= low;)
	{
		printf("Searching in array: ");
		for (i = low; i < high; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = low + (high - low) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			high = i - 1;
		else
			low = i + 1;
	}

	return (-1);
}
