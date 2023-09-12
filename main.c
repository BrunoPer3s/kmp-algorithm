#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int kmp(char P[M], char T[N], int* comparacoes) {
  int aux[M];
  preProcessadorPadrao(P, aux);
  
  //Printing the lps array
   printf("\n");
   for(int i = 0; i < M; i++) {
    printf("%d ", aux[i]);
  }

  int k = 0;

  for(int i = 0; i < N; i++) {
    while(k > 0 && (P[k] != T[i])) {
      k = aux[k-1];
      (*comparacoes)++;
    }      
    
    if(T[i] == P[k]) {
      k++;
      (*comparacoes)++;
    }
      
    if(k == M) {
      i++;
      return (i - k);
    }
    
  }
  return -1;
}

int main() {
  clock_t start, end;
  start = clock();

  FILE* arq = fopen("data.txt", "r");

  if(arq == NULL) {
    printf("Erro Arquivo\n");
    return 0;
  }

  char texto[N];
  char padrao[M] = "onions";

  int i = 0;
  while (feof(arq) == 0) {
    fscanf(arq, "%c", &texto[i]);
    i++;
  }

  for (int i = 0; i < N; i++) {
    printf("%c", texto[i]);
  }

  int comparacoes = 0;
  int index = kmp(padrao, texto, &comparacoes);

  printf("\nAchado em T[%d] / com N %d Comparacoes\n", index, comparacoes);

  for(int i = 0; i < M; i++) {
    printf("%c", texto[index]);
    index++;
  }

  end = clock();
  printf("\n\nTempo: %8f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);

  return 0;
}
