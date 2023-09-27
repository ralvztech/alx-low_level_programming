#include "lists.h"

/**
 * listint_len - Returns the element in a linked listint_t
 * @h: head
 * Return: 0
 */

size_t listint_len(const listint_t *h)
{
	int count = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
