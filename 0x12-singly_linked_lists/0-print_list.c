#include <lists.h>
#include <stdio.h>

/**
 * print_list - prints list.
 * @h: param list
 * Return: struct
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
			if (h->str == NULL)
		{
			printf("[%zu] (nil)\n", count);
		}
		else
		{
			printf("[%zu] %s\n", count, h->str);
		}
		h = h->next;
		count++;
	}
	return (count);
}

