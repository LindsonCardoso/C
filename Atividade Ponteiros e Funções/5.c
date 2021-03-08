#include <stdio.h>
#include <stdlib.h>
/*Crie um programa que contenha uma função que permita passar por parâmetro dois
 números inteiros A e B. A função deverá calcular a soma entre estes dois números
  e armazenar o resultado na variável A. Esta função não deverá possuir retorno,
  mas deverá modificar o valor do primeiro parâmetro. Imprima os valores de A e B
  na função principal*/

void somar(int *vA, int vB){
  int r, n;
    r = *vA + vB;
    printf("\nResultado da operacao: %i",r);
    n = *vA;
    *vA = r;
  }

int main(){
  int A = 0, B = 0;
  printf("Digite um numero: ");
  scanf("%i",&A);
  printf("Digite outro numero: ");
  scanf("%i",&B);
  somar(&A,B);
  printf("\n\nValores:\nA= %i\nB= %i",A,B);
    return EXIT_SUCCESS;

}
