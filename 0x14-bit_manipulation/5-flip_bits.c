#include "main.h"
/**
 * flip_bits - the number of bits you would need to flip to get
 * from one number to another
 * @n: original number
 * @m: destiny number
 * Return: number of flips
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i, nf = 0;
	unsigned long int ii = sizeof(unsigned long int) * 8;

	for (i = 0; i < ii; i++)
	{
		if ((m & 1) != (n & 1))
			nf += 1;
		n = n >> 1;
		m = m >> 1;
	}
	return (nf);
}
