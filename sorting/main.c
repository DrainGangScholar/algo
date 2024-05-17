#include "include/bubble_sort.h"
#include "include/common.h"
#include "include/heap.h"
int main(int argc, char *argv[]) {
  int size = atoi(argv[1]);
  int *array = init_array(size, 1, 100);
  heap *h = min_create_heap(size, size, array);
  print_array(&h->array[0], 1);
  printf("%d\n", extract_root(h, MIN_HEAP));
}
