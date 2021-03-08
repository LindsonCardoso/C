#include <stdio.h>
#include <stdlib.h>
/* Crie uma função que receba como parâmetro um array e o imprima. Não utilize
 índices para percorrer o array, apenas aritmética de ponteiros. */

int main(){
  int array[5], *p;
  printf("Digite os elementos do array\n");
  for(int i=0; i<5;i++){
    printf("Elemento [%i] = ",i);
    scanf("%i",&array[i]);
  }

  for(int j=0; j<5;j++){
    p=&array[j];
    printf("\nElementos [%i] = %i\n",j,*(p++));
    }

  return 0;
}
