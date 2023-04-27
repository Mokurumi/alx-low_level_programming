#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 *
 * @head: double pointer to the head of the list.
 * @str: pointer to the string to be added to the list.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n_node, *temp;

	n_node = malloc(sizeof(list_t));

	if (n_node == NULL)
		return (NULL);

	n_node->str = strdup(str);

	if (n_node->str == NULL)
	{
		free(n_node);
		return (NUL);
	}

	n_node->len = strlen(str);

	/* Set the next pointer of the new node to NULL */
	n_node->next = NULL;

	/* If the list is empty, set the head to the new node */
	if (*head == NULL)
	{
		*head = n_node;
	}
	else
	{
		/* Traverse the list to the last node */
		temp = *head;

		while (temp->next != NULL)
			temp = temp->next;

		/* Set the next pointer of the last node to the new node */
		temp->next = n_node;
	}

	return (n_node);
}
