#include <stdio.h>
#include <stdlib.h>
/*Crie um programa contendo um array de inteiros contendo 5 elementos. Utilizando
 apenas aritmética de ponteiros, leia este array do teclado e imprima o dobro de
 cada elemento. */

int main(){
  int array[5], *p;
  printf("Digite os elementos do array\n");
  for(int i=0; i<5;i++){
    printf("Elemento [%i] = ",i);
    scanf("%i",&array[i]);
  }

  for(int j=0; j<5;j++){
    p=&array[j];
    printf("\nElementos [%i] = %i",j,(*p*2));
    }

  return 0;
}
