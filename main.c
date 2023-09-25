#include <stdio.h>
#include <stdlib.h>

#define M 6
#define N 620

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
  int count = 0;

  //Printing the lps array
   for(int i = 0; i < M; i++) {
    printf("%d ", aux[i]);
  }

  int k = 0;

  for(int i = 0; i < N; i++) {
    printf("\ni =%d\n", i);
    while(k > 0 && (P[k] != T[i])) {
      printf("\nT[%d] -> %c != P[%d] -> %c\n", i, T[i], k, P[k]);
      count++;
      k = aux[k-1];
    }      
    
    if(T[i] == P[k]) {
      printf("\nT[%d] -> %c == P[%d] -> %c\n", i, T[i], k, P[k]);
      k++;
      count++;
    }

    if(k == 0 && T[i] != P[k]) {
      printf("\nT[%d] -> %c != P[%d] -> %c\n", i, T[i], k, P[k]);
      count++;
    }
      
    if(k == M) {
      i++;
      printf("\nComp = %d\n", count);
      return (i - k);
    }
  }
  return -1;
}

int main() {
  FILE* arq = fopen("data.txt", "r");

  if(arq == NULL) {
    printf("Erro na leitura do arquivo!\n");
    return 0;
  }

  char texto[N];
  char padrao[M] = "onions";

  int i = 0;
  while (feof(arq) == 0) {
    fscanf(arq, "%c", &texto[i]);
    i++;
  }

  int index = kmp(padrao, texto);

  printf("\n%d ", index);

  for(int i = 0; i < M; i++) {
    printf("%c", texto[index]);
    index++;
  }

  return 0;
}
