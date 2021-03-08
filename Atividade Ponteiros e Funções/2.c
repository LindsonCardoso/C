#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis
do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.
 */
int main() {

    //inputs
    int a=0, b=0;

    printf("digite um numero: ");
    scanf("%i",&a);
    getchar();
    printf("digite segundo numero: ");
    scanf("%i",&b);
    getchar();

    //inputs
    int *end_a = &a;
    int *end_b = &b;

    printf("\nendereco A = %i",&end_a);
    printf("\nendereco B = %i",&end_b);
    getchar();
    if(*end_a > *end_b){
      if(&a > &b)
        printf("\nmaior endereço: %i\nvalor: %i",&end_a,a);
    }else{
        printf("\nmaior endereço: %i\nvalor: %i",&end_b,b);
      }
    getchar();

      printf("\n");
      return EXIT_SUCCESS;
}
