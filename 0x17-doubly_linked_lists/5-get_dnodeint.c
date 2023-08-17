#include "lists.h"

/**
 * get_dnodeint_at_index - Get the nth node of a doubly linked list
 * @head: Pointer to the head of the list
 * @index: Index of the node (starting from 0)
 *
 * Return: Address of the nth node, or NULL if it doesn't exist
 *
 * Description: This function returns the address of the node at the given
 * index in a doubly linked list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}
