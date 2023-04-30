#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 *
 * @head: pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		*head = NULL;

	/* Traverse the list and free each node */
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}

	*head = NULL;
}
