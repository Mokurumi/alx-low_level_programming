#include "function_pointers.h"

/**
 * int_index - search for ints
 *
 * @array: array to print
 * @size: size of array
 * @cmp: pointer to function
 *
 * Return: Nothing.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0)
	{
		return (-1);
	}

	for (int i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
		{
			return (i);
		}
	}

	return (-1);
}
