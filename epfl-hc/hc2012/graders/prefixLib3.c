#include <stdio.h>
#include <stdlib.h>
#include "prefixLib3.h"

const int MAX_LENGTH = 22;

int main(int argc, char** argv){
  int ntc;
  scanf("%d\n", &ntc);
  int tc;
  for(tc=0;tc<ntc;++tc) {
    int nlines;
    scanf("%d\n", &nlines);
    char** array = (char**) calloc(nlines, sizeof(char*));
    int i;
    for(i=0;i<nlines;++i) {
      array[i] = (char*) calloc(MAX_LENGTH, sizeof(char));
      scanf("%21s\n", array[i]);
    }

    int result = minimalNumberToMakeFull(nlines, array);
    printf("%d\n", result);

    for(i=0;i<nlines;++i) {
      free(array[i]);
    }
    free(array);
  }
  return 0;
}
