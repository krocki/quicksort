#include <stdint.h>
extern uint64_t partition(uint64_t *arr, uint64_t len, uint64_t pivot);

void partition_all(uint64_t *arr, uint64_t len) {

  uint64_t p1;
  p1=partition(arr, len, arr[0]);
  if (p1 > 1) partition_all(arr, p1);
  if (len-p1-1 > 1) partition_all(arr+p1+1, len-p1-1);

}
