#include "search_algos.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * jump_list - searches for a value in a sorted list of integers using the
 *             Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located or NULL if value
 *         is not present in head or if head is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump, i;
	listint_t *current, *prev;

	if (list == NULL || size == 0)
		return (NULL);

	jump = sqrt(size);
	current = list;
	while (current->n < value)
	{
		prev = current;
		for (i = 0; i < jump; i++)
		{
			if (current->next == NULL)
				break;
			current = current->next;
		}
		if (current->next == NULL)
			break;
		printf("Value checked at index [%lu] = [%d]\n", current->index,
		       current->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
	       current->index);
	current = prev;
	while (current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index,
		       current->n);
		if (current->next == NULL)
			return (NULL);
		current = current->next;
	}
	printf("Value checked at index [%lu] = [%d]\n", current->index,
	       current->n);
	if (current->n == value)
		return (current);
	return (NULL);
}
