#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Search for a value in a sorted array of integers
 * using Interpolation search algorithm
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located,
 * or -1 if not found or if array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	int pos, low, high;

	if (array == NULL || size == 0)
		return (-1);

	low = 0;
	high = size - 1;

	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos = low +
			(((double)(high - low) / (array[high] - array[low])) *
			 (value - array[low]));

		if (pos < 0 || pos >= (int)size)
			return (-1);

		printf("Value checked array[%d] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	printf("Value checked array[%d] is out of range\n", high);
	return (-1);
}
