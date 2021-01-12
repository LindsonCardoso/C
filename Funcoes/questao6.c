#include <stdio.h>
#include <string.h>
#include <math.h>

int banc(long n){

  int num,aux3,aux4, soma = 0,soma1 = 0, d, result;
  float aux1, aux2 ;
  long guarda,guarda2, guarda3;
    aux1 = (n % 10); // traz o ultimo algarismo 4
    soma += aux1;
    //soma = aux1;
    guarda = n / 10;

    //verficando o penultimo algarismo 1
    aux2 =  guarda % 10; // 1
    soma += aux2;
    //soma = aux2;
    guarda2 = guarda / 10;

    //verficando o antipenultimo algarismo 3
    aux3 = guarda2 % 10;
    soma += aux3;
    guarda3 = guarda2 / 10;

    aux4 = guarda3 % 10;
    soma+= aux4;
    d = soma;

    result = d % 10;

    return(result);

}



 int main() {
   long conta; //7314

while (conta != 0) {


 printf("\nInforme a conta: ");
 scanf("%i",&conta);

     printf("\n");

  printf("digito verifidador: %i",banc(conta));

}


  return 0;
}


/*
long aumenta o espaço tomado pela variável, e portanto aumenta seu valor
máximo e/ou sua precisão. Pode ser usado com int e double.
O padrão C de 1999 adicionou um terceiro modificador,
suportado pelos compiladores mais recentes, inclusive o gcc:
long long, que aumentaria ainda mais a capacidade da variável.
Alguns deles suportam esse modificador apenas para o tipo int,
e outros suportam também para double.
Uma observação é necessária: segundo o padrão, não existe nenhuma
garantia de que uma variável short int é menor que uma variável int,
nem que long int é maior que int. Apenas é garantido que int não é maior
que long nem menor que short. De fato, nos sistemas x86 de 32 bits (ou seja,
 a maioria dos computadores pessoais atualmente), o tamanho de int é igual ao
  de long. Geralmente, int será o tamanho nativo do processador — ou seja, 32
   bits num processador de 32 bits, 16 bits num processador de 16 bits etc.
*/
