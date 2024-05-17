#include "common.h"
#define SIZE 32

typedef struct heap {
  int *array;
  int size;
  int capacity;
} heap;

void min_heapify(heap *h, int size, int index) {
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int min = index;
  if (left < size && left >= 0 && h->array[left] < h->array[min]) {
    min = left;
  }
  if (right < size && right >= 0 && h->array[right] < h->array[min]) {
    min = right;
  }
  if (min == index) {
    return;
  }
  SWAP(h->array[min], h->array[index]);
  min_heapify(h, size, min);
}

void max_heapify(heap *h, int size, int index) {
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  int max = index;

  if (left < size && left >= 0 && h->array[left] > h->array[max]) {
    max = left;
  }
  if (right < size && right >= 0 && h->array[right] > h->array[max]) {
    max = right;
  }
  if (max == index) {
    return;
  }
  SWAP(h->array[max], h->array[index]);
  max_heapify(h, size, max);
}

void min_insert_helper(heap *h, int index) {
  if (index < 0) {
    return;
  }
  int parent = (index - 1) / 2;
  if (parent < 0) {
    return;
  }
  if (h->array[parent] > h->array[index]) {
    SWAP(h->array[parent], h->array[index]);
    min_insert_helper(h, parent);
  }
}

void max_insert_helper(heap *h, int index) {
  if (index < 0) {
    return;
  }
  int parent = (index - 1) / 2;
  if (parent < 0) {
    return;
  }
  if (h->array[parent] < h->array[index]) {
    SWAP(h->array[parent], h->array[index]);
    max_insert_helper(h, parent);
  }
}

bool min_insert(heap *h, int val) {
  if (h->size >= h->capacity) {
    return false;
  }
  h->array[h->size] = val;
  min_insert_helper(h, h->size);
  return true;
}

bool max_insert(heap *h, int val) {
  if (h->size >= h->capacity) {
    return false;
  }
  h->array[h->size] = val;
  max_insert_helper(h, h->size);
  return true;
}

heap *min_create_heap(int capacity, int size, int *vals) {
  heap *h = (heap *)malloc(sizeof(heap));
  assert(h != NULL);

  h->capacity = capacity;
  h->array = (int *)malloc(capacity * sizeof(int));
  assert(h->array != NULL);

  int i;
  for (i = 0; i < size; i++) {
    h->array[i] = vals[i];
  }
  h->size = i;
  i = (h->size - 2) / 2;
  while (i >= 0) {
    min_heapify(h, h->size, i);
    i--;
  }
  return h;
}

heap *max_create_heap(int capacity, int size, int *vals) {
  heap *h = (heap *)malloc(sizeof(heap));
  assert(h != NULL);

  h->capacity = capacity;
  h->array = (int *)malloc(capacity * sizeof(int));
  assert(h->array != NULL);

  int i;
  for (i = 0; i < size; i++) {
    h->array[i] = vals[i];
  }

  h->size = i;
  i = (h->size - 2) / 2;
  while (i >= 0) {
    max_heapify(h, h->size, i);
    i--;
  }
  return h;
}

void heap_sort(heap *h, bool flag) {
  if (flag == INCREASING) {
    for (int i = h->size - 1; i >= 0; i--) {
      SWAP(h->array[0], h->array[i]);
      max_heapify(h, i, 0);
    }
    return;
  }
  if (flag == DECREASING) {
    for (int i = h->size - 1; i >= 0; i--) {
      SWAP(h->array[0], h->array[i]);
      min_heapify(h, i, 0);
    }
    return;
  }
}

int extract_root(heap *h, bool flag) {
  int temp = h->array[0];
  SWAP(h->array[0], h->array[h->size - 1]);
  h->size -= 1;
  if (flag == MIN_HEAP) {
    min_heapify(h, h->size, 0);
  } else {
    max_heapify(h, h->size, 0);
  }
  return temp;
}
