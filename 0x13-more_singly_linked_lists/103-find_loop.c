#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 *
 * @head: pointer to the head node of the linked list.
 *
 * Return: The address of the node where the loop starts,
 *         or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head, *hare = head;

	while (tortoise != NULL && hare != NULL && hare->next != NULL)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			hare = head;

			while (hare != tortoise)
			{
				hare = hare->next;
				tortoise = tortoise->next;
			}

			return (tortoise);
		}
	}

	return (NULL);
}
