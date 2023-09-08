#include <stdio.h>
#define m 5

void lps(int aux[M], char P[M]) {
  int j = 0;
  aux[0] = j;
  for(int i = 1; i < m; i++) {
    while(j > 0 && P[j] == P[i]) {
      j = aux[j-1];
    }
    if(P[j] == P[i]) {
      j++;
    }
    aux[i] = j;
  }
}
