#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro,
 real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada
 variável usando os ponteiros. Imprima os valores das variáveis antes e após a modificação. */
int main() {

    //inputs
    int *p, int v1=0;
    float *real; float v2=0.0;
    char *C; char c;


    printf("digite um inteiro: ");
    scanf("%i",&v1);
    getchar();
    printf("digite um real: ");
    scanf("%f",&v2);
    getchar();
    printf("digite um char: ");
    scanf("%c",&c);
    printf("\nInputs");
    //logic
    p = &v1;
    real = &v2;
    C = &c;

  	printf("\nInteiro: %i",*p);
    printf("\nReal: %.1f",*real);
    printf("\nchar: %c",*C);

    printf("\n\nInputs atualizados");
    getchar();
    *p = 2;
    *real = 1.0;
    *C = 'b';
    printf("\nInteiro: %i",*p);
    printf("\nReal: %.1f",*real);
    printf("\nchar: %c",*C);
    getchar();
    return EXIT_SUCCESS;

}
