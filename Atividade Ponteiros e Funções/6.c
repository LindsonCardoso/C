#include <stdio.h>
#include <stdlib.h>
/*Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereço de cada posição dessa matriz.*/

void matrizF(){
  float mat[3][3],i,j;
    for(float i=0; i<3;i++){
      for(float j=0; j<3;j++){
      printf("\nmatriz[%.1f][%.1f]\n",i,j);
      }
    }


  }

int main(){
  matrizF();
  return 0;
}
