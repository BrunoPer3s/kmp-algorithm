#include <stdio.h>
#define m 5

void lps(int aux[m], char P[m]) {
  int j = 0;
  aux[0] = j;
  for(int i = 1; i < m; i++) {
    while(j > 0 && P[j] != P[i]) {
      j = aux[j-1];
    }
    if(P[j] == P[i]) {
      j++;
    }
    aux[i] = j;
  }
}

int main() {
  char P[m] = "aabac";
  int aux[m];

  lps(aux, P);
  for(int i = 0; i < m; i++) {
    printf("%d ", aux[i]);
  }
  

  
  return 0;
  
}
