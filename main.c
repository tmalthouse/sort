#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "selsort.h"
#include "mergesort.h"
#include "test.h"
#include "qsort.h"

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("More than 2 args!\n");
    exit(0);
  }

  void (*sort)(int64_t *array, uint64_t len);
  sort = quicksort;
  if (sort!=NULL) {
    randomtests(50,100000,sort);
  } else {
    printf("Function is null!\n" );
  }
  return 0;
}

void print_arr (int64_t *arr, uint64_t len) {
  for (uint64_t i=0; i<len; i++) {
    printf("%"PRId64",  ", arr[i]);
  }
}
