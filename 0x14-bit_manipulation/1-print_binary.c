#include "main.h"

/**
 *print_binary - print the binary representation of a number
 *@n: unsigned long int
 *Return: void
 */

void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}

  /*Recursively print the binary representation of the upper bits.*/
	print_binary(n >> 1);

  /*Print the least significant bit.*/
	_putchar((n & 1) + '0');
}

