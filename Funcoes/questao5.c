#include <stdio.h>

#include <stdlib.h>

#include <string.h>



float pesofeminino(float altura){

    float resultado;

    resultado=((62.1*altura)-44.7);

    return(resultado);

}

float pesomasculino(float altura){

    float resultado;

    resultado=((72.7*altura)-52);

    return(resultado);

}

int main()

{

    float altura;

    char s[1];



    printf("Informe a altura: (Digite -1 para encerrar): ");

    scanf("%f",&altura);

    while(altura!=-1){

        printf("Informe o sexo: M=masculino F=feminino: ");
        scanf("%s",&s);


        printf("Informe a altura: (Digite -1 para encerrar): ");

        scanf("%f", &altura);

        if(s == "M"){
                 printf("\n\n\n\nteste\n\n\n\n");
                 printf("O peso ideal eh: %.2f", pesomasculino(altura));
             }
             else if(s == "F"){
               printf("\n\n\n\nteste 2\n\n\n\n");
                 printf("O peso ideal eh: %.2f", pesofeminino(altura));

             }

    }



    return 0;

}
