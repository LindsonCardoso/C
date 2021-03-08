#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Elabore uma função que receba duas strings como parâmetros e verifique se a
 segunda string ocorre dentro da primeira. Use aritmética de ponteiros para
 acessar os caracteres das strings
 */

void verificar(char *str1, char *str2)
  {
    int aux,count = 0;

    if (strlen(str1) <= strlen(str2)) {
      printf("string dois nao esta na 1\n");
    }else{
      for (int i = 0; i <strlen(str1); i++) {
          if (str2[0]==str1[i]) {
            for (int j = 0; j <strlen(str2)-1; j++) {
              if (str2[j] == str1[i++])
                count++;
            }
          }
          if(count==strlen(str2)){
              break;
      }
        }//fim do for
        if (count==strlen(str2)) {
          printf("\n =======Veriricação ======\n String %s ocorre dentro da primeira string  %s ",str2,str1);
        }else
          printf("String 2 nao esta ocorre na primeira string!");
      }//fim do if else
  }


int main(){
  char str_1[100], str_2[21];
  printf("Digite os elementos do array\n");
  fgets(str_1, 100, stdin);
  fgets(str_2, 21, stdin);
  printf("String 1: %s\nString 2: %s\n",str_1,str_2);
  verificar(str_1,str_2);
  return 0;

}
