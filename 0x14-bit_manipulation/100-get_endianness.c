#include "main.h"
/**
 * get_endianness - function that checks the endianness
 * Return: No return 0.
 */
int get_endianness(void)
{
	int b = 255, *e;
	char *st;

	e = &b;
	st = (char *)e;

	if (*st ==  0)
		return (0);
	return (1);
}
