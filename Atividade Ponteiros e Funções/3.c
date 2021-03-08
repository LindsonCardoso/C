#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que leia 2 valores inteiros e chame uma função que receba estas
 2 variáveis e troque o seu conteúdo (por referência), ou seja, esta função é
 chamada passando duas variáveis A e B por exemplo e, após a execução da função,
  A conterá o valor de B e B conterá o valor de A.
*/

void trocar(int *v1, int *v2)//apontadores
{
    int n; //varivel de manipulação dos valores dos ponteiros
    n = *v1;
    *v1 = *v2;
    *v2 = n;
  }

int main(){

  int a = 0, b = 0;
  printf("Digite um numero: ");
  scanf("%i",&a);
  printf("Digite outro numero: ");
  scanf("%i",&b);
  printf("Valores digitados:\nA= %i\nB= %i\n",a,b);
  trocar(&a,&b);
  printf("\nDepois de rodar a função os valores\nA= %i\nB= %i",a,b);
  return EXIT_SUCCESS;

}
