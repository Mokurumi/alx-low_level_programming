#include "lists.h"

/**
 * delete_nodeint_at_index - delete a new node at a given position
 *
 * @head: pointer to the head node of the linked list.
 * @idx: index of position where the new node should be added, starting at 0.
 * @n: data (n) to be stored in the new node.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *current = *head, *prev = NULL;

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	while (current != NULL && i < index)
	{
		prev = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	prev->next = current->next;
	free(current);

	return (1);
}
