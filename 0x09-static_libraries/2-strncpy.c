#include "main.h"
/**
* _strncpy - function that displays copies of a string
*
* @dest: input parameter
*
* @src: input parameter
*
* @n: number of copies
*
* Return: dest (Success)
*/
char *_strncpy(char *dest, char *src, int n)
{
int c;

c = 0;
while (c < n && src[c] != '\0')
{
dest[c] = src[c];
c++;
}
while (c < n)
{
dest[c] = '\0';
c++;
}
return (dest);
}
