#include <stdio.h>

/*Considere a seguinte declaração: int A, *B e **C; Escreva um programa que leia
a variável A e calcule e exiba o dobro e o triplo desse valor utilizando apenas
os ponteiros B e C. O ponteiro B deve ser usada para calcular o dobro e C o triplo.*/

int main(){

    int A = 0, *B, **C, t;
    printf("informe um valor par A: ");
    scanf("%i",&A);

    B = &A; // B aponta para endereço de A
    C = &B; // C aponta para a A e *C aponta para B;
    printf("%i\n%i",(*B*2),(**C*3));


}
