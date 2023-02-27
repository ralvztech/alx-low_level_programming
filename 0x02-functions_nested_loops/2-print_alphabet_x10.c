#include "main.h"
/**
 * main - A program to print alphabet 10x
 *
 * Return: 0 (Success)
 */
void print_alphabet_x10(void)
{
	char c;
	int i = 0;

	while(i <= 9)
	{
		for (c = 'a'; c <= 'z'; c++)
		_putchar(c);
		{
			_putchar('\n');
			i++;
		}
	}
}
