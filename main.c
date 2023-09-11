#include <stdio.h>

#define M 6
#define N 11

void preProcessadorPadrao(char P[M], int aux[M]) {	
  int j = 0;
  aux[0] = j;
  for(int i = 1; i < M; i++) {
    while(j > 0 && (P[j] != P[i])) {
      j = aux[j-1];
    }
    if(P[j] == P[i]) {
      j++;
    }
    aux[i] = j;
  }
}

int kmp(char P[M], char T[N]) {
  int aux[M];
  preProcessadorPadrao(P, aux);
  
  //Printing the lps array
   for(int i = 0; i < M; i++) {
    printf("%d ", aux[i]);
  }

  int k = 0;

  for(int i = 0; i < N; i++) {
    while(k > 0 && (P[k] != T[i])) {
      k = aux[k-1];
    }      
    
    if(T[i] == P[k]) {
      k++;
    }
      
    if(k == M) {
      i++;
      return (i - k);
    }
    
  }
  return -1;
}

int main() {
  char texto[N] = "onionionspl";
  char padrao[M] = "onions";

  int index = kmp(padrao, texto);

  printf("\n%d ", index);

  for(int i = 0; i < M; i++) {
    printf("%c", texto[index]);
    index++;
  }

  return 0;
}
