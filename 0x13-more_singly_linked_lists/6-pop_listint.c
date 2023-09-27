#include "lists.h"

/**
 * pop_listint - Entry Point
 * @head: head
 * Return: 0
 */

int pop_listint(listint_t **head)
{
	if (*head == NULL)
	{
		return 0;
	}
	listint_t *temp = *head;
	int n = temp->n;
	*head = temp->next;
	free(temp);
	return n;
}

