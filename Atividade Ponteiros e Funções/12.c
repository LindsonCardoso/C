#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Escreva uma função que aceita como parâmetro um array de inteiros com N valores,
 e determina o maior elemento do array e o número de vezes que este elemento
 ocorreu no array. Por exemplo, para um array com os seguintes
 elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve retornar para o programa
  que a chamou o valor 15 e o número 3 (indicando que o número 15 ocorreu 3 vezes).
   A função deve ser do tipo void.
*/

int aux = 0, count = 0;

void arr(int n_elemento, int *array){
int i, aux = array[0], reg;
    for (i = 0; i<n_elemento; i++)
    {
        printf("%i\t",array[i]);
        if(aux<=array[i]) aux = array[i];
        for (i = 0; i < n_elemento; i++){
              if (aux == array[i]){
                count++;
                reg = array[i];
              }

              }
        }
              printf("\nNumero: %i ocorreu %i vezes",reg,count);
}

int main()
  {
    setlocale(LC_ALL,"portuguese");
        int n;
        printf("Digite a quantidade numeros para o array: ");
        scanf("%i",&n);
        int vet[n];
          for (int i = 0; i <n; i++) {
              printf("posição [%i] = ",i+1);
              scanf("%i",&vet[i]);
          }
          arr(n,array);//chamando a função
}
