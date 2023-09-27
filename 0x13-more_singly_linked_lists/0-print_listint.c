#include <stdio.h>
#include "lists.h"

/**
 * print_linstint - A function that prints all element of linstint_t lists
 * @h: head
 * Return: 
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	if (h == NULL)
		return 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
  return (count);
}

