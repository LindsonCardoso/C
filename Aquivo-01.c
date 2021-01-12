#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Dados{
  int cod;
  char tipo[21];
  char bairro[21];
  char status[21];
  float area_const;
  float area_total;
  char padrao[21];
  float preco_surg;
  float preco_negc;
}Dados_cad;


void cadastro();


int main(void){
  setlocale(LC_ALL,"portuguese");

//inciando minhas variaveis para manipulação
int i,j,k = 0, quant_imv = 0, op, achou = 0, pesquisarCod, guardaCod, contImov = 0;
char aux_tipo[1],aux_padrao[1];

  FILE*fp;  //declaracoa da estrutura
  fp = fopen("imobiliaria.txt","wb"); // o arquvivo se chama imobiliaria e
  if ((fp = fopen("imobiliaria.txt","wb")) == NULL) {
 printf("\n Arquivo imobiliaria.txt não pode ser aberto");
 }



scanf("%i",&op);
do {
  printf("\n-------Bem Vindo a ImoBit-------\n\nDesenvolvido por:\nLindson\n\n-----------MENU---------\n\n1 - CADASTRAR\n2 - PESQUISAR\n3 - LISTAR IMOVEIS A VENDA\n4 - ALTERAR PREÇO DE VENDA\n5 - LISTAR IMOVEIS POR TIPO\n6 - LISTAR IMOVEIS POR PADRAO\n7 - ALTERAR PREÇO DE NEGOCIAÇÃO\n8 - ENCERRAR\n\nDIGITE UMA OPÇÃO: ") ;


  switch(op){
      case 1:
      cadastro();

   break;
  /*   case 2:
      pesquisa();
      break;
  case 3:
      lista();
      break;
  case 4:
      listatipo();
      break;
  case 5:
      listapadrao();
      break;
  case 6:
      alterar();
      break;
  case 7:
      excluir();
      break;*/
  default:
      printf("\nOpcao Invalida");
      break;
  }
  getchar();
      getchar();

} while(op != 0);

}//fim do int main

//inicio das minhas funcoes

void Cadastro(){
  int i,j,k = 0, quant_imv = 0, op, achou = 0, pesquisarCod, guardaCod, contImov = 0;

  printf("======================================================================\n");
  printf("\nINFORME A QUANTIDADE DE IMOVEIS A SER CADASTRADO =  ");
  scanf("%i",&quant_imv);
  printf("\n======================================================================\n");

                      if (contImov == quant_imv) { // verificado se ja foram cadatrado imoveis
                        printf("Imoveis ja encontrados, Não é possivel cadastrar novamente");
                        break;
                      }
                      else{
                                printf("\nInsira o novo código de identificação do imóvel:");
                                scanf("%d", &guardaCod);
                                achou = 0;
                          for( i=0; i<quant_imv; i++)
                              {
                                if (dados_imov[i].cod ==  guardaCod)
                                {
                                    achou = 1;
                                    printf("Codigo ja existe\n");
                                    break;
                                }
                              }
                              if (achou == 1)break;
                              else{

                              dados_imov[k].cod = guardaCod; //ATUALIZANDO O REGISTRO CODIOG COM O VALOR DA VARIAVEL INFORMADO ACIMA

                                printf("\n Informe o tipo do imovel, C = Casa / A = Apartamento / L = Lote:");
                                scanf("%s", &tipo[i]);
                    fflush(stdin);

                                 printf("\n Informe o bairro: ");
                                  scanf("%s", &bairro[i]);
                  fflush(stdin);
                               printf("\n Informe a área construída em M²: ");
                               scanf("%f", &area[i]);
                   fflush(stdin);
                               printf("\n Informe a área total: ");
                               scanf("%d", &total[i]);
                   fflush(stdin);
                               printf("\n Qual o padrão de acabamento do imóvel (P = Popular / B = Bom / E = Excelente): ");
                               scanf(" %s", &padrao[i]);

                                 printf("\n Informe o preço sugerido (em reais) \n R$ ");
                                 scanf("%f", &sugerido[i]);

                          printf("\nCadastro finalizado!\n\n");

                          //atualizando o registro com os dados
                          strcpy(dados_imov[k].tipo,tipo[i]);
                          strcpy(dados_imov[k].bairro,bairro[i]);
                          dados_imov[k].area_const = area[i];
                          dados_imov[k].area_total = total[i];
                          dados_imov[k].preco_surg = sugerido[i];
                          strcpy(dados_imov[k].padrao, padrao[i]);


                          k++; //atualiza os index de k
                          contImov++;

fclose();
}
