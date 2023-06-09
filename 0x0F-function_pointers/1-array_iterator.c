#include "function_pointers.h"

/**
 * array_iterator - iterates the array
 *
 * @array: array to print
 * @size: size of array
 * @action: pointer to function
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
