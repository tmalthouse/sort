#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void quicksort (int64_t *array, uint64_t len) {//This is a "dutch-flag style" quicksort (en.wikipedia.org/wiki/Dutch_national_flag_problem)
  if (len<=1) return;
  int64_t pivot = array[rand()%len];
  uint64_t lcount = 0, ecount = 0, gcount = 0;
  for (uint64_t i=0; i<len; i++) {
    if (array[i] < pivot) {
      lcount++;
    } else if (array[i] > pivot) {
      gcount++;
    } else {
      ecount++;
    }
  }

  int64_t less[lcount], greater[gcount], equal[ecount];
  uint64_t l_ind = 0, g_ind = 0, e_ind = 0;
  for (uint64_t i=0; i<len; i++) {
    if (array[i] < pivot) {
      less[l_ind] = array[i];
      l_ind++;
    } else if (array[i] > pivot) {
      greater[g_ind] = array[i];
      g_ind++;
    } else {
      equal[e_ind] = array[i];
      e_ind++;
    }
  }

  assert(lcount+ecount+gcount == len);
  quicksort (less, lcount);
  quicksort (greater, gcount);

  memcpy(array, less, lcount*sizeof(int64_t));
  memcpy(array+lcount, equal, ecount*sizeof(int64_t));
  memcpy(array+lcount+ecount, greater, gcount*sizeof(int64_t));
}
