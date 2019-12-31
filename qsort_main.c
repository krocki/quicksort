#ifndef IO
#define IO 1
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "timer.h"

void randomize(uint64_t *arr, uint64_t len, uint64_t min, uint64_t max) {
  for (uint64_t i=0; i<len; i++) {
    arr[i] = min + rand() % (max-min+1);
  }
}

extern uint64_t partition(uint64_t *arr, uint64_t len, uint64_t p);
extern void partition_all(uint64_t *arr, uint64_t len);

void print_arr(uint64_t *arr, uint64_t len, uint64_t div) {
  for (uint64_t i=0; i<len; i++)
  {
    if (div == i) putchar(']');
    printf("%04llx%s", arr[i], i == (len-1) ? "\n" : " ");
    if (div == i) putchar('[');
  }
  puts("");
}

int check_arr(uint64_t *arr, uint64_t len) {
  uint64_t i = 1;
  do {
    if (arr[i] < arr[i-1]) return -1;
  } while (i++ < len);
  return 0;
}

int main(int argc, char **argv) {

  uint64_t len = argc > 1 ? strtol(argv[1], NULL, 10) : (1 << 18);
  uint64_t arr[len];
  srand(time(NULL));
  randomize(arr, len, 0, (1 << 20));
  timeit(partition_all(arr, len));
  int ok = check_arr(arr, len);
  printf("%s\n", ok==0 ? "TEST OK" : "FAIL");
  return ok;

}
