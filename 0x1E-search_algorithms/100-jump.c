#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array of integers
 * using Jump search algorithm
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located,
 * or -1 if not found or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int step = sqrt(size);
	int prev = 0;

	if (array == NULL || size == 0)
		return (-1);


	while (array[(step < size ? step : size) - 1] < value)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		prev = step;
		step += sqrt(size);
		if (prev >= (int)size)
			return (-1);
	}

	while (array[prev] < value)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		prev++;

		if (prev == fmin(step, size))
			return (-1);
	}

	printf("Value checked array[%d] = [%d]\n", prev, array[prev]);

	if (array[prev] == value)
		return (prev);

	return (-1);

}
