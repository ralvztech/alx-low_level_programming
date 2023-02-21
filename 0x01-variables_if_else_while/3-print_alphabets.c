#include <stdio.h>
#include <stdlib.h>
/**
 * main - A program that prints lower and upper case
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;
	char d;

	c = 'a';
	d = 'A';
	while
		(c <= 'z') {
			putchar(c);
			d++;
		}
	while
		(d <= 'z') {
			putchar(c);
			d++;
		}
	putchar('\n');
	return (0);
}
