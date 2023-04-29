#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list.
 *
 * @head: double pointer to the head of the list.
 * @n: pointer to the string to be added to the list.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *n_node;

	/* Allocate memory for the new node */
	n_node = malloc(sizeof(listint_t));

	if (n_node == NULL)
		return (NULL);

	/* Copy the int */
	n_node->n = n;

	/* Set the next pointer of the new node to the head of the list */
	n_node->next = *head;

	/* Set the head of the list to the new node */
	*head = n_node;

	return (n_node);
}
