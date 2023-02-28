#include <stdio.h>
#include "main.h"
/**
 * main - print all numbers from input to 98
 *
 * Return: the starting number
 */
void print_to_(int n)
{
	if (n >= 98)
	{
		while (n > 98)
			printf("%d, ", n--);
		printf("%d\n", n);
	}
	else
	{
		while (n < 98)
			printf("%d, " n++);
		printf("%d\n", n);
	}
}
