#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>





int compare (const void * a, const void * b)
{
  if ( *(int64_t*)a <  *(int64_t*)b ) return -1;
  if ( *(int64_t*)a == *(int64_t*)b ) return 0;
  if ( *(int64_t*)a >  *(int64_t*)b ) return 1;
  else return 2;
}

bool test(int64_t *array, uint64_t len, void (*sort)(int64_t *array, uint64_t len)) {
  int64_t qs[len];
  memcpy(qs, array, len*sizeof(int64_t));
  qsort(qs, len, sizeof(int64_t), compare);

  int64_t selsort[len];
  memcpy(selsort, array, len*sizeof(int64_t));
  (*sort) (selsort, len);

  bool ans;
  if (!memcmp(selsort, qs, len*sizeof(int64_t))) {
    printf("The arrays matched!\n");
    ans = true;
  } else {
    printf("The arrays didn't match!\n");
    ans = false;
  }
  return ans;
}

void randomtests (uint64_t num_tests, uint64_t test_len, void (*sort)(int64_t *array, uint64_t len)) {
  bool result = true;
  int64_t *random = calloc(test_len, sizeof(int64_t));
  if (random == NULL) {
    printf("We couldn't allocate the array. Sorry!\n");
    exit(1);
  }
  for (uint64_t i=0; i<num_tests; i++) {
    for (uint64_t j=0; j<test_len; j++) {
      random[j] = rand()%10000;
    }
    if (!test (random, test_len, sort)) {
      result = false;
    }
  }
  free(random);

  if (result) {
    printf("The arrays all matched! Your function is good!\n");
  } else {
    printf("Your function doesn't work!\n");
  }
}
