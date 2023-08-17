#include "lists.h"

/**
 * sum_dlistint - Calculate the sum of all integers in a doubly linked list
 * @head: Pointer to the head of the list
 *
 * Return: Sum of all integers in the list, or 0 if the list is empty
 *
 * Description: This function calculates and returns the sum of all integer
 * values in a doubly linked list (dlistint_t).
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
