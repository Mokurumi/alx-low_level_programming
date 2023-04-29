#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 *
 * @head: pointer to the head node of the linked list.
 * @idx: index of position where the new node should be added, starting at 0.
 * @n: data (n) to be stored in the new node.
 *
 * Return: pointer to the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *current = *head, *prev = NULL, *new_node;

	while (current != NULL && i < idx)
	{
		prev = current;
		current = current->next;
		i++;
	}

	if (i < idx)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (prev == NULL)
		*head = new_node;
	else
		prev->next = new_node;

	new_node->next = current;

	return (new_node);
}
