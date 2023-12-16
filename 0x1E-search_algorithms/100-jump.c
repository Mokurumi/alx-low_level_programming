#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array of integers using Jump search algorithm
 * @array: Pointer to the first element of the sorted array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where the value is located, or -1 if not found or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int i, step, prev, curr;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);

	prev = 0;
	curr = step;

	while (curr < (int)size && array[curr] < value)
	{
		printf("Value compared: %d\n", array[curr]);

		prev = curr;
		curr += step;

		if (curr >= (int)size)
			curr = size - 1;
	}

	printf("Value compared: %d\n", array[curr]);

	for (i = prev; i <= curr; ++i)
	{
		printf("Value compared: %d\n", array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
