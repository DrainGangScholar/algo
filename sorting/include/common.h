#ifndef COMMON_H
#define COMMON_H
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define DECREASING true
#define INCREASING false
#define MIN_HEAP true
#define MAX_HEAP false
#define SWAP(a, b)                                                             \
  do {                                                                         \
    typeof(a) temp = a;                                                        \
    a = b;                                                                     \
    b = temp;                                                                  \
  } while (0)
#define random_number(min, max) min + rand() % (max - min + 1)
void print_array(const int *array, const unsigned long size) {
  for (int i = 0; i < size - 1; i++) {
    printf("%d,", array[i]);
  }
  printf("%d\n", array[size - 1]);
}
bool is_sorted(const int *array, unsigned long size) {
  assert(array != NULL);
  bool is_sorted = true;
  for (int i = 0; i < size - 1; i++) {
    if ((array[i] > array[i + 1])) {
      is_sorted = false;
      return is_sorted;
    }
  }
  return is_sorted;
}
static int *init_array(unsigned long size, int min, int max) {
  assert(size > 0);
  int *array = (int *)malloc(sizeof(int) * size);
  assert(array != NULL);
  for (int i = 0; i < size; i++) {
    array[i] = random_number(min, max);
  }
  return array;
}
#endif /* COMMON_H */
