#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located or NULL if value
 *         is not present in head or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev;

	if (list == NULL)
		return (NULL);

	current = list;
	while (current->n < value)
	{
		prev = current;
		if (current->express == NULL)
		{
			while (current->next != NULL)
				current = current->next;
			break;
		}
		current = current->express;
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
