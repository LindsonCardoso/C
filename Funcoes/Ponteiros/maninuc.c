#include <stdio.h>
#include <string.h>


//passando por 2 valores
int soma_e_troca(int  *p ,int *q)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;

    t=(*p + *q);
    return(t);
}


 int main() {

   int i= 10, j=20;

   printf("Depois da execucao da funcao: i= %d e j=%d, soma = %d\n",i,j,soma_e_troca(&i,&j));
  return 0;
}
