#include "main.h"

/**
 *set_bit - sets the value of a bit to 1 at a given index
 *@n: number to modified
 *@index: position to be set to 1
 *Return: 1 on success, -1 on error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int b = 1;

	if (index > 32)
		return (-1);

	b = b << index;
	*n = *n | b;

	return (1);
}

