#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

void mergesort (int64_t *array, uint64_t len) {
  if (len < 2) {
    return;
  }
  int64_t arr1[len/2];
  int64_t arr2[len-len/2];

  memcpy (arr1, array, sizeof(int64_t)*(len/2));
  memcpy (arr2, array+(len/2), sizeof(int64_t)*(len-len/2));

  mergesort(arr1, len/2);
  mergesort(arr2, len-len/2);

  uint64_t a1_ind = 0, a2_ind = 0;

  for (uint64_t i=0; i<len; i++) {
    if (arr1[a1_ind]<=arr2[a2_ind] && a1_ind<len/2) {
      array[i] = arr1[a1_ind];
      a1_ind++;
    } else {
      array[i] = arr2[a2_ind];
      a2_ind++;
    }
  }
}
