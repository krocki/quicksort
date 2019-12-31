#include <stdint.h>

void swap(uint64_t *arr, uint64_t i, uint64_t j) {
  uint64_t t0, t1;
  t0 = arr[i], t1 = arr[j];
  arr[j] = t0;
  arr[i] = t1;
}

void partition(uint64_t *arr, uint64_t len, uint64_t p) {

  uint64_t l=0, e=0, r=len-1;

  while (e<=r) {
    if (p > arr[e]) { swap(arr, l, e); e++; l++; }
    else if (p == arr[e]) { e++; }
    else { r--; swap(arr, e, r); }
  }

}
