#include "lists.h"

/**
 * dlistint_len - Count the number of elements in a doubly linked list
 * @h: Pointer to the head of the list
 *
 * Return: Number of elements in the list
 *
 * Description: This function counts the number of elements in a doubly
 * linked list (dlistint_t).
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;
	const dlistint_t *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
