#include "main.h"
/**
 * main - A program to check lowercase character
 *
 * Return: 1 for lowercase or 0 for anything else
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	return (0);
}
