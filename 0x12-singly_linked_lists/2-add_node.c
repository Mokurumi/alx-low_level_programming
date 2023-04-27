#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list.
 *
 * @head: double pointer to the head of the list.
 * @str: pointer to the string to be added to the list.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *n_node;

	/* Allocate memory for the new node */
	n_node = malloc(sizeof(list_t));

	if (n_node == NULL)
		return (NULL);

	/* Copy the string */
	n_node->str = strdup(str);

	if (n_node->str == NULL)
	{
		free(n_node);
		return (NULL);
	}

	/* Set the length of the string */
	n_node->len = strlen(str);

	/* Set the next pointer of the new node to the head of the list */
	n_node->next = *head;

	/* Set the head of the list to the new node */
	*head = n_node;

	return (n_node);
}
