#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * isdigit - Function to check if a string contains only digits.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */

int is_digit(char *str)
{
  for (int i = 0; str[i]; i++) {
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
  }
  return 1;
}

/* Function to multiply two positive numbers*/
int mul(int num1, int num2)
{
  int res = 0;
  for (int i = 0; i < num2; i++) {
    res += num1;
  }
  return res;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Error\n");
    exit(98);
  }

  if (!is_digit(argv[1]) || !is_digit(argv[2])) {
    printf("Error\n");
    exit(98);
  }

  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[2]);

  int result = mul(num1, num2);

  printf("%d\n", result);

  return 0
}