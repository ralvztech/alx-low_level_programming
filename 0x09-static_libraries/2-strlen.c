#include "main.h"
/**
* _strlen - read string parameter
*
* @s: string parameter to be read
*
* Return: Length of string
*/
int _strlen(char *s)
{
int i;

i = 0;
while (*s != '\0')
{
i++;
s++;
}
return (i);
}
