#include "main.h"

/**
 *get_bit - get the value of a bit at a given index
 *@n: number
 *@index: the index of a bit
 *Return: the bit or -1 if unable to fetch it
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index < 0 || index >= 32)
	{
		return -1;
	}
	return (n >> index) & 1;
}

