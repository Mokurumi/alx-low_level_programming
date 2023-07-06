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
	listint_t *slow, *fast, *tmp;
	size_t count = 0;

	if (h == NULL)
		return (0);

	slow = *h;
	fast = *h;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) /* loop detected */
		{
			/* Break the loop */
			fast = *h;
			while (slow != fast)
			{
				tmp = slow;
				slow = slow->next;
				fast = fast->next;
			}
			tmp->next = NULL;
			break;
		}
	}

	return (count);
}
