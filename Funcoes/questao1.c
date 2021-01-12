/*
1)	Faça um programa em C que faça a conversão de moedas (dólares ↔ reais) utilizando uma função que receba do programa principal dois parâmetros (passados por valor), sendo um valor real positivo (reais ou dólares) e uma letra (“D” para efetuar a conversão de dólares para reais, ou “R” para efetuar a conversão de reais para dólares). Assuma que a cotação do dólar seja de R$3,15. Esta função deverá enviar a resposta para o programa principal para então ser mostrado para o usuário. O programa deverá efetuar um número indeterminado de repetições, assuma que o valor 0 indica final de repetição.

*/
#include <stdio.h>

//incio da minha funcao
float convert(float valor, char Letra){
  //variavel local
  float result = 0;

        if(Letra == 'R')
        result = valor / 3.15;  //real para dolares
          else
            if(Letra == 'D')
              result = valor * 3.15; //convertendo dola para real
                else
                  printf("Letra nao encontrada\n");

        return(result);//todos os resultados
}

 int main() {
   float d, r;
   char L;

   printf("Infome o valor: ");
   scanf("%f",&r);

   while (r != 0)
   {

     printf("Informe a letra D = Dolar /  R = Real: ");
     scanf("%s",&L);
     printf("Valor convertido: %.2f\n",convert(r,L));
     printf("Infome o valor: ");
     scanf("%f",&r);

}//fim da funcoa
  return 0;
}
