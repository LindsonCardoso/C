/*
3)	Faça um programa que calcule, através de uma função, o valor de uma prestação em atraso. Para tanto, utilize a fórmula PREST = VALOR + (VALOR * (TAXA/100)*TEMPO). O usuário deverá informar o valor da prestação, a taxa de juros e o tempo em atraso, estes valores deverão ser passados para a função como parâmetros. O valor corrigido deverá ser mostrado no programa principal
*/
#include <stdio.h>
#include <string.h>


float calc(float valp, float tax, float temp){

    float result;

    result = valp + (valp * (tax/100) * temp);

    return(result);


}


 int main() {

   float valor,taxa_juros, tempo;



     printf("Informe o valor da prestação : ");
     scanf("%f",&valor);

          printf("Informe taxa de juros : ");
          scanf("%f",&taxa_juros);

               printf("Informe o tempo de atraso : ");
               scanf("%f",&tempo);

 printf("Valor da prestação eh: %.2f",calc(valor,taxa_juros,tempo));;

     printf("\n");



  return 0;
}
