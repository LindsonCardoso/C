#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct Passagem{
 char cod[4];
  int cadeiras_dispon;
  int reserva;
}Dados;

int main(){
    setlocale(LC_ALL,"portuguese");

  int i;

  //definindo variavel especial do struct
  Dados dados[REG];

//pecorrendo o meu vetor
for ( i = 0; i < REG; i++) {
  printf("informe o codigo da passagem: \n");
  scanf("%s",dados[i].cod);
  printf("informe o numero de cadeiras disponiveis: \n");
  scanf("%i",&dados[i].cadeiras_dispon);
  printf("informeo numero de cadeiras reservadas: \n");
  scanf("%i",&dados[i].reserva);
    fflush(stdin);
}

for (i=0; i< REG; i++){ //saída de dados
    printf("Voo %i: cod: %s\n", i+1, dados[i].cod);
    printf("Lugares disponíveis do voo %i: %i\n", i+1, dados[i].cadeiras_dispon);
    printf("Lugares reservados do voo %i: %i\n", i+1, dados[i].reserva);
}

return 0;
}

-------------------------------------------------------------------------------

/*
2)
Foi realizada uma pesquisa de algumas características físicas de 50
habitantes de uma certa região. De cada habitante foram coletados os
seguintes dados: sexo (M – masculino ou F – feminino), altura, idade e
cor dos olhos (A – azuis, V – verdes ou C – castanhos). Faça um algoritmo
que leia esses dados e armazene-os em um vetor de registros. Determine:

a)a média das idades das pessoas com olhos castanhos e altura superior a 1,60m
b)a maior idade entre os habitantes
c)a quantidade de mulheres com altura superior a 1,80m
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

//fiXANDO tamanho do meu vetor
#define VET 2

//INICIANDO MEU REGISTRO COMO ALIAS
typedef struct Pessoas{
    char sexo[1];
    float altura;
    int idade;
    char olhos[1];
  }Dados;//MINHA VARIAVEL ESPECIAL

int main(){

    //DEFININDO SET LOCAL PARA ACENTUAÇÃO
    setlocale(LC_ALL,"portuguese");

  //DEFINNDO MINHAS VARIAVEIS PARA MANIPULAR
  int i,j, count = 0, somador = 0, MAIOR_IDADE = 0, mulheres = 0, count_mulher = 0, guarda = 0;
  float  media;

  //definindo variavel especial do struct
  Dados dados[VET];

//pecorrendo o meu vetor E DANDO ENTRADA NOS MEUS DADOS DO REGISTRO
for ( i = 0; i < VET; i++) {
  printf("Informe o sexo M = masculino F = feminino: \n");
  scanf("%s",&dados[i].sexo);

  printf("informe Altura: \n");
  scanf("%f",&dados[i].altura);

  printf("informe a idade: \n");
  scanf("%i",&dados[i].idade);

  printf("Informe a cor dos olhos V = VERDE, A = AZUL, C = CASTANHO:  \n");
  scanf("%s",&dados[i].olhos);
  fflush(stdin);
  printf("\n");

  //pecorrendo MEU VETOR PARA

        if((!strcmp(dados[i].olhos, "C")) && (dados[i].altura > 1.60))
        {
            //QUANTIDADE DE PESSOAS
            somador += dados[i].idade;
            count++;
          }

          //verifcando a maior idade entre os habitantes
          if (dados[i].idade > MAIOR_IDADE) MAIOR_IDADE = dados[i].idade;

          //verificando mulheres COM IDADE SUPERIO A 1.80
          if((!strcmp(dados[i].sexo, "F")) && (dados[i].altura > 1.80)) count_mulher++;

}



      //TIRANDO A MEDIA
      media = somador/count;
        printf("\nmédia das idades das pessoas com olhos castanhos e altura superior a 1.60 É:  %.2f",media);

          printf("\nA maior idade entre os habitantes É:  %d\n",MAIOR_IDADE);

            printf("A quantidade de mulheres com altura superior a 1.80 É:  %i",count_mulher);



return 0;
}

_________________________________________________________________________________


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

//fiXANDO tamanho do meu vetor
#define VET 2
#define CONTA 2
//INICIANDO MEU REGISTRO COMO ALIAS cliente


typedef struct Clientes{
    char nome[21];
    int idade;
    char bairro[21];
    char rua[21];
    char numero;
    int cpf[11];
    int numeroConta;
    float saldoAtual;
    int buscar[11];
  }Dados_cliente;//MINHA VARIAVEL ESPECIAL


typedef struct Contas{

}Dados_conta;


int main(){

    //DEFININDO SET LOCAL PARA ACENTUAÇÃO
    setlocale(LC_ALL,"portuguese");

  //DEFINNDO MINHAS VARIAVEIS PARA MANIPULAR
  int i, j, buscar[11], count = 0, MAIOR_IDADE = 0, mulheres = 0, count_mulher = 0, guarda ,quant_conta;
  float  media, somador = 0;

  //definindo variavel especial do struct
  Dados_cliente dados_cliente[VET];
  Dados_conta dados_conta[CONTA];

//pecorrendo o meu vetor E DANDO ENTRADA NOS MEUS DADOS DO REGISTRO
for ( i = 0; i < VET; i++) {
  printf("Informe o nome: ");
  scanf("%s",&dados_cliente[i].nome);

  printf("\ninforme a idade: ");
  scanf("%i",&dados_cliente[i].idade);

  printf("\ninforme o endereço\n");
  printf("Bairro: ");
  scanf("%s",&dados_cliente[i].bairro);
  printf("Rua: ");
    scanf("%s",&dados_cliente[i].rua);
   printf("Numero: ");
  scanf("%s",&dados_cliente[i].numero);

  printf("\nInforme o cpf: ");
  scanf("%i",&dados_cliente[i].cpf);

//pecorrendo a quantida de contas dele
for ( j = 0; j < CONTA; j++) {
  printf("\nInforme o numero da conta: ");
  scanf("%i",&dados_cliente[i].numeroConta);
  printf("informe o saldo atual R$ ");
  scanf("%f",&dados_cliente[i].saldoAtual);

}
        printf("\n\n************Iniciando_outro_cadastrO***********\n\n");


}



printf("informando as contas cadastradas e seus clientes\n");


for ( i =0; i<VET; i++) {
    printf("\nNome: %s\n",dados_cliente[i].nome);
for ( j =0; j<VET; j++) {
    printf("conta: %i\n",dados_cliente[i].numeroConta);
    printf("Saldo: %.2f\n",dados_cliente[i].saldoAtual);

}

}


/*
printf("\n\nInformando contas de um determinado cliente\nInforme o CPF do cliente para buscar: ");
scanf("%i",dados_cliente[11].buscar);
if(dados_cliente[11].buscar == dados_cliente[i].cpf){
  for ( i = 0; i < VET; i++) {
    for( j = 0; j < 1; j++) {
    printf("\nConta: %i\nSaldo: %.2f",dados_conta[j].numeroConta,dados_conta[j].saldoAtual);

  }
}
  }
*/

/*  printf("\n\nInformando o somatorio das contas de um determinado cliente\nInforme o CPF do cliente para buscar: ");
  scanf("%i",dados_cliente[11].buscar);
  if(dados_cliente[11].buscar == dados_cliente[i].cpf)fflush(stdin);{
    for ( i = 0; i < 1; i++) {
      for( j = 0; j < 1; j++) {
        somador += dados_cliente[i].saldoAtual;
      printf("\nSomatorio das contas de %s\n",dados_cliente[i].nome);
      printf("Total %.3f\n",somador);
    }
  }
}*/



return 0;
}


/*
1)	Faça um programa em C que receba os seguintes dados referentes
ao vazamento de óleo nas 100 principais cidades do litoral brasileiro:
•	cidade,
•	estado (SE, AL, CE, PE, BA, PB, RN e MA),
•	toneladas de óleo recolhidas e
•	quantidade de voluntários cadastrados.

O programa deve:
a)	Mostrar o total de óleo recolhido nas praias brasileiras.
b)	Mostrar o nome da cidade, e seu respectivo estado, com a maior quantidade de óleo recolhida.
c)	Mostrar a média de voluntários cadastrados.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>

//fiXANDO tamanho do meu vetor
#define VET 2
#define CONTA 2
//INICIANDO MEU REGISTRO COMO ALIAS cliente


typedef struct Pesquisa{
    char cidade[21];
    float idh;
  }Dados_cid;//MINHA VARIAVEL ESPECIAL

int main(){

    //DEFININDO SET LOCAL PARA ACENTUAÇÃO
    setlocale(LC_ALL,"portuguese");

  //DEFINNDO MINHAS VARIAVEIS PARA MANIPULAR
  int i, j,total = 0, maior_valor = 0, quant_ole = 0,menor_valor = 0,idh_valor = 0, somador = 0;
  int muitobaixo;
  char guarda_cid[21], guarda_est[2];
  float  media;

  //definindo variavel especial do struct
  Dados_cid dados_cid[VET];

 //pecorrendo o meu vetor E DANDO ENTRADA NOS MEUS DADOS DO REGISTRO
for ( i = 0; i < VET; i++) {

  printf("Informe a cidade: ");
  scanf("%s",&dados_cid[i].cidade);
fflush(stdin);
  printf("\ninforme o estado: ");
  scanf("%f",&dados_cid[i].idh);

  printf("______________________________________________________\n");


if (dados_cid[i].idh < menor_valor)
{
menor_valor = dados_cid[i].idh;
}

somador += dados_cid[i].idh;


for ( j = 0; j < VET; j++) {
  if (dados_cid[i].idh >= 0.00 && dados_cid[i].idh <= 0.499) {
    strcpy(guarda_cid, dados_cid[i].cidade);
    idh_valor = dados_cid[i].idh;
  }
}

}
media=somador/VET;

      printf("Cidade com menor idh %.2f\n",menor_valor);
      printf("média de voluntários cadastrados %.2f\n",media);
      printf("cidade com idh %s, idg: %.2f\n",guarda_cid,idh_valor);
return 0;
}
