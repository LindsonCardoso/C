#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que leia dois valores inteiros e chame uma função que receba
estes 2 valores de entrada e retorne o maior valor na primeira variável e o
menor valor na segunda variável. Escreva o conteúdo das 2 variáveis na tela.
*/

void trocar(int *p, int *q){
  int n;
    if(*p < *q){
        n = *q;
        *q = *p;
        *p = n;
    }
  }

int main(){
  int i = 0, j = 0;
  printf("Digite um numero: ");
  scanf("%i",&i);
  printf("Digite outro numero: ");
  scanf("%i",&j);
  printf("Valores digitados:\nA= %i\nB= %i\n",i,j);
  trocar(&i,&j);
  printf("\nDepois de rodar a função os valores\nA= %i\nB= %i",i,j);
  return EXIT_SUCCESS;

}
