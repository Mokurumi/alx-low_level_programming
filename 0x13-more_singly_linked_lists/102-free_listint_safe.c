#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list.
 *
 * @h: pointer to the head node of the linked list.
 *
 * Return: the size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *tmp, *head = *h;

	while (head != NULL)
	{
		if (head <= head->next)
		{
			*h = NULL;
			free(head);
			count++;
			break;
		}

		tmp = head;
		head = head->next;
		free(tmp);
		count++;
	}

	return (count);
}
