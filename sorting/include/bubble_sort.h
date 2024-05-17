#include "common.h"
void bubble_sort(int *array, const unsigned long size) {
    assert(array != NULL);
  bool swapped;
  for (int i = 0; i < size - 1; i++) {
    swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swapped = true;
        SWAP(array[j], array[j + 1]);
      }
    }
    if (swapped == false) {
      break;
    }
  }
}
