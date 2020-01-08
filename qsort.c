#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "timer.h"

typedef struct {
  int data;
} entry;

int compare(const void *p, const void *q) {
  return (((const entry*)p)->data) -
         (((const entry*)q)->data);
}

void swap(entry *a, entry *b) {
  entry t = *a; *a = *b; *b = t;
}

int partition(entry *arr, int len, entry p) {

  int l=0, e=0, r=len-1;

  while (e<=r) {
    int c = compare(&p, &arr[e]);
    if (c > 0) { swap(&arr[l++], &arr[e++]); }
    else if (c < 0) { swap(&arr[e], &arr[r--]); }
    else { e++; }
  }
  return r;
}

void sort(entry *arr, int len) {

  int p = partition(arr, len, arr[len/2]);
  if (p > 1) sort(arr, p);
  if (len-p-1 > 1) sort(arr+p+1, len-p-1);

}

void randomize(entry *arr, int len) {
  for (int i=0; i<len; i++) arr[i].data = rand() % (1 << 20);
}

void print(entry *arr, int len) {
  for (int i=0; i<len; i++)
   printf("%lu, ", arr[i].data);
  puts("");
}

int main(int argc, char **argv) {

  int n = argc > 1 ? strtol(argv[1], NULL, 10) : 16;
  srand(0);

  entry *arr = (entry*)malloc(sizeof(entry) * n);

  randomize(arr, n);

  puts("before sort");
  print(arr, n);
  timeit(sort(arr, n));
  puts("after sort");
  print(arr, n);

  free(arr);
  return 0;
}
