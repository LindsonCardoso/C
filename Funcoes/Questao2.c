#include <stdio.h>
#include <string.h>
//incio da minha funcao
float clinic(int valorCons){
  //variavel local
  float salarioLiquid = 0, salarioBruto = 0, result = 0;

    salarioBruto = valorCons * 150; //valor total do salario
    if(valorCons > 40)
      salarioLiquid = salarioBruto * 0.85;
          else
          salarioLiquid = salarioBruto  * 0.92;
     return(salarioLiquid);
}

 int main() {
   int mat, consul;
   char nome[12];

   printf("informe a matricula do medido (0 para encerrar): ");
   scanf("%i",&mat);

while (mat != 0) {

     printf("Digite o nome: ");
     scanf("%s",&nome);
     printf("Informe a quantidada de consultas feita no mes: ");
     scanf("%d",&consul);

     printf("\n");

     printf("Matricula: %i\n",mat);
     printf("Salario Bruto: R$ %.2f\n",consul * 150.00);//salario bruto
     printf("Salario Liquido: R$ %.2f\n",clinic(consul));

     printf("\n");


     printf("informe a matricula do medico (0 para encerrar): ");
     scanf("%i",&mat);
     }
  return 0;
}
