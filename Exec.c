#include <stdio.h>

#include <string.h>

void inico(){

  printf("Universidade: Unimontes\n");
  printf("Centro: CCET\n");
  printf("Departamento: Ciencia da computação\n");
  printf("Curso: Sistema de informacao\n");
  printf("Academico: Lindson\n");
  printf("Periodo: I\n");
  printf("Semestre: 2 Ano 2020\n");


}

float conceito(float notas[3], float nota_trabalho){
    int i;
    char letra[1];
    float maior_nota1 = 0, maior_nota2 = 0, total;


for ( i = 0; i < 3; i++) {
  if(notas[i] > maior_nota1){
    if(maior_nota1 > maior_nota2 ){
      maior_nota2 = maior_nota1;
    }
      maior_nota1 = notas[i];

    }
      if(maior_nota1 >= maior_nota2 && notas[i] != maior_nota1){
            if(notas[i  ] > maior_nota2){
                maior_nota2=notas[i];

            }
        }


        total = maior_nota1 + maior_nota2 + nota_trabalho;



        if(total > 90 && total<100)
          strcpy(letra,"A");
        else
          if(total > 80 && total < 89)
          strcpy(letra,"B");
          else
            if(total > 70 && total < 79)
            strcpy(letra,"C");
            else
              if(total>60&&total < 69)
                strcpy(letra,"D");
                else
                  if(total > 50 && total < 59)
                    strcpy(letra,"E");
                      else
                        if(total > 0 && total < 49)
                        strcpy(letra,"F");



}
}


 int main() {
   int i;
   float notas[3],n2,n3,nt;
   float Taxa_juros, tempo;

   inico();

   for ( i = 0; i < 3; i++) {
     printf("Informe a nota da prova : ");
     scanf("%f",&notas[i]);
 }
 printf("Informe o Nota do trabalho: ");
 scanf("%f",&nt);

     printf("\n");



     printf("Nota final desse aluno  eh: R$ %.2f",conceito(notas,nt));


  return 0;
}
