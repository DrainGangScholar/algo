#include "include/bubble_sort.h"
#include "include/common.h"
#include "include/heap.h"
#define NUMBER 16
int main(void) {
  int *array = init_array(NUMBER, 1, 100);
  heap *h = min_create_heap(NUMBER, NUMBER, array);
  //heap_sort(h, INCREASING);
  print_array(h->array, h->size);
  printf("%d\n", extract_root(h, MIN_HEAP));
  print_array(h->array, h->size);
}
