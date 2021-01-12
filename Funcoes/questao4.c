#include <stdio.h>
#include <stdlib.h>
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

char *conceito(float notas[3], float nota_trabalho){
    int i;
    char letra;
    float maior_nota1 = 0, maior_nota2 = 0, total;


for ( i = 0; i < 3; i++) {
  if(notas[i] >= maior_nota1){
    if(maior_nota1 >= maior_nota2 ){
      maior_nota2 = maior_nota1;
    }
      maior_nota1 = notas[i];


    }
      if(maior_nota1 >= maior_nota2 && notas[i] != maior_nota1){
            if(notas[i] >= maior_nota2){
                maior_nota2=notas[i];

            }
        }


        total = maior_nota1 + maior_nota2 + nota_trabalho;
        if(total >= 90 && total<=100)
        return('A');
          if(total >= 80 && total <= 89)
            return('B');
            if(total >= 70 && total <=79)
            return('C');
              if(total>=60&&total <= 69)
              return('D');
                  if(total >= 50 && total <= 59)
                return('E');


}
}


 int main() {
   int i;
   float notas[3],n2,n3,nt;

   inico();

   for ( i = 0; i < 3; i++) {
     printf("Informe a nota da prova : ");
     scanf("%f",&notas[i]);
 }
 printf("Informe o Nota do trabalho: ");
 scanf("%f",&nt);

     printf("\n");

     printf("Nota final desse aluno  eh: %c",conceito(notas,nt));


  return 0;
}
