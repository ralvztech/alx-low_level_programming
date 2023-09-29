#include "main.h"

/**
 *Binary_to_uint - converts binary numbers to an unsigned int
 *@b: string to converts
 *Return: 0 if entry is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int val = 0;
	int i = 0;

	if (b == NULL)
	{
		return 0;
	}
	while (b[i] == '0' || b[i] == '1')
	{
		/*Found another digit.*/
		val <<= 1;
		val += b[i] - '0';
		i++;
	}
	return val;
}

