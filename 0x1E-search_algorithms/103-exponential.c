#include "search_algos.h"
#include <stdio.h>

/**
 * exponential_search - Search for a value in a sorted array of integers
 * using Exponential search algorithm
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located,
 * or -1 if not found or if array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	int i, j, mid, start, end;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	i = 1;
	while (i < (int)size && array[i] <= value)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		i *= 2;
	}

	start = i / 2;
	end = (i < (int)size) ? i : (int)size - 1;

	printf("Value found between indexes [%d] and [%d]\n", start, end);

	while (start <= end)
	{
		mid = start + (end - start) / 2;
		printf("Searching in array: ");
		for (j = start; j <= end; ++j)
			printf("%d%s", array[j], (j == end) ? "\n" : ", ");

		if (array[mid] == value)
			return mid;
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return (-1);
}
