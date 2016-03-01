#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>

#include "test.h"


void ssort (int64_t *array, uint64_t len) {
  int64_t lowest = array[0];
  for (uint64_t i=0; i < len; i++) {
    if (array[i]<lowest) {
      lowest = array[i];
      int64_t tmp = array[0];
      array[0] = array[i];
      array[i] = tmp;
    };
  }

  if (len>2) {
    ssort (array+1, len-1);
  }
}
