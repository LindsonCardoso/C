#include <stdio.h>
#include <string.h>

//valores passado por paramtro e sadndo um restorno em void

void soma_e_troca(int  *p ,int *q, int *saida)
{
    int t;
    t = *p;
    *p = *q;
    *q = t;

    *saida=(*p + *q);

}


 int main() {

   int i= 10, j=20, resul = 0;
   soma_e_troca(&i,&j,&resul);
   printf("Depois da execucao da funcao: i= %d e j=%d, soma = %d\n",i,j,resul);
  return 0;
}
