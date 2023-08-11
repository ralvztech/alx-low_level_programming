#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Determine the last digit of a number
 *
 *print the last digit of the number stored in the variable n
 *if greater than 5 is greater than 5, if 0 is 0, if less than 6 is less than 6 and not 0

 *Return: Always 0
 */
int main(void)
{
	int n;
	int lastd;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastd = n % 10;

	if ((n % 10) > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n", n, n % 10);
	}
	else if ((n % 10) < 6 && (n % 10) != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n", n, n % 10);
	}
	else
	{
		printf("Last digit of %d is %d and is 0\n", n, n % 10);
	}
	return (0);
}
