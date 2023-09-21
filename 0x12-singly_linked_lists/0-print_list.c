#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 *
 *
 */

size_t print_list(const list_t *h) {
  size_t count = 0;
  while (h != NULL) {
    if (h->str == NULL) {
      printf("[%zu] (nil)\n", count);
    } else {
      printf("[%zu] %s\n", count, h->str);
    }
    h = h->next;
    count++;
  }
  return count;
}


typedef struct {
  char *str;
  struct list_t *next;
} list_t;

int main() {
  list_t *head = NULL;

  /* Add some elements to the list.*/
  list_t *node1 = malloc(sizeof(list_t));
  node1->str = "This is the first element.";
  node1->next = NULL;
  head = node1;

  list_t *node2 = malloc(sizeof(list_t));
  node2->str = "This is the second element.";
  node2->next = NULL;
  node1->next = node2;

  /* Print the list.*/
  size_t count = print_list(head);

  /* Free the list.*/
  while (head != NULL) {
    list_t *next = head->next;
    free(head);
    head = next;
  }

  printf("The list has %zu nodes.\n", count);

  return 0;
}

