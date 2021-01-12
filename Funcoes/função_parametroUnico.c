#include <stdio.h>

// passagem por paramentro unico valor
int fatorial(int n){
    int i, fat =1;
    if (n==0) return(1);
    else {
    for ( i = 1; i <=n ; i++) fat = fat * i;
    }
    return(fat);
}


 int main() {


   int num, result;
   printf("Informe o valor: ");
   scanf("%i",&num);

   //atribuino o resultado a uma variavel
  // result = fatorial(num);
  // printf("O fatorial de %d e %d\n",num, result);

// retorno dentro do printf
 printf("O fatorial de %d e %d\n",num, fatorial(num));

  return 0;
}
