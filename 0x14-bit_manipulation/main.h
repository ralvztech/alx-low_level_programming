#ifndef _MAIN_H
#define _MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/*holbertons putchar */
int _putchar(char c);


/*task 0*/
unsigned int binary_to_uint(const char *b);
/*task 1*/
void print_binary(unsigned long int n);
/*task 2*/
int get_bit(unsigned long int n, unsigned int index);
/*task 3*/
int set_bit(unsigned long int *n, unsigned int index);
/*task 4*/
int clear_bit(unsigned long int *n, unsigned int index);
/*task 5*/
unsigned int flip_bits(unsigned long int n, unsigned long int m);
/*task 6 aka 100*/
int get_endianness(void);

#endif
