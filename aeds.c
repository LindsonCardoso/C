#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

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


//FILE*fp;

//variavel global para receber um valor
  int quant_imv = 0;
  int guardQ = 0;

//func
  void quant(){
    printf("\nINFORME A QUANTIDADE DE IMOVEIS A SER CADASTRADO =  ");
    scanf("%i",&quant_imv);
    guardQ += quant_imv;
  }



//criando minha struct para variavel especial
void cadastro(){
    FILE *fp;
    int i,j, op, guardaCod, achou = 0, k = 0, contImov = 0; //variaveis de manipulacao

 Dados_cad ImoBit[guardQ];


         float negociado = 0;;
         char avenda[] = "AV";
         char vendido[] = "V";
         //strcpy(ImoBit[k].status, avenda);
         setlocale(LC_ALL,"portuguese");


     fp = fopen("imobiliaria.txt", "a+b");
      if(fp == NULL) {
              perror("Erro");
              exit(1);
          }

{
   for(i=0;i<guardQ;i++){
          printf("\n Insira o codigo de identificação do imóvel: ");
          scanf("%d", &ImoBit[i].cod);

          printf("\n Informe o tipo do imovel, C = Casa / A = Apartamento / L = Lote:");
          scanf("%s", &ImoBit[i].tipo);
          fflush(stdin);

          printf("\n Informe o bairro: ");
          scanf("%s", &ImoBit[i].bairro);
          fflush(stdin);

                       printf("\n Informe a área construída em M²: ");
                       scanf("%f", &ImoBit[i].area_const);
           fflush(stdin);

                       printf("\n Informe a área total: ");
                       scanf("%d", &ImoBit[i].area_total);
           fflush(stdin);

                       printf("\n Qual o padrão de acabamento do imóvel (P = Popular / B = Bom / E = Excelente): ");
                       scanf(" %s", &ImoBit[i].padrao);

                         printf("\n Informe o preço sugerido (em reais) \n R$ ");
                         scanf("%f", &ImoBit[i].preco_surg);

                    //    printf("\n Informe o status do imovel V = Vendido e AV = A Venda: ");
                    //   scanf("%s", &status[i]);


                  printf("\nCadastro finalizado!\n\n");



                  fwrite(&ImoBit[i], sizeof(Dados_cad),1,fp);

                }
             }
        printf("\n Cadastro finalizado!");
    fclose(fp);
}//fim da funcao



void pesquisar(){


/*  FILE *fp;
  fp = fopen("imobiliaria.txt", "rb");

  if (fp == NULL) {
         printf("erro ao abrir o arquivo.\n");
         exit(1);
     }


    int pesquisaid,i, op;
   Dados_cad ImoBit[guardQ];

   printf("Digite o codigo do imovel: ");
   scanf("%d",&pesquisaid);
   printf("\n ========== DADO DO IMOVEL ==========\n\n");

   //while(fread(&ImoBit[i], sizeof(Dados_cad), 1, fp))
   fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
   for ( i = 0; i < guardQ; i++) {
            if (pesquisar == ImoBit[i].cod) {
                fread(&ImoBit[i], sizeof(Dados_cad), 1, fp);
                   printf("\nCodigo: %d\nTipo: %s\nArea: %.2f\nArea Tptal: %.2f\nPadrao: %s\nPreco Sugerido: R$%.2f\n",ImoBit[i].cod,ImoBit[i].tipo,ImoBit[i].area_const,ImoBit[i].area_total,ImoBit[i].padrao,ImoBit[i].preco_surg);
                    break;
}

 }
        //  printf("\nStatus do imovel V = Vendido e AV = A Venda: %s",dados_imov[i].status);
        //  printf("\npreço Negociado: R$ %.2f",negociado);


fclose(fp);
*/
}
void listatipo();
void listapadrao();
void alterar();
void excluir();


int  main()
{
  setlocale(LC_ALL,"portuguese");

  int op,i, buscar;
  int contImov = 0;
  char vendido[] = "V";
  char avenda[] = "AV";
//  strcpy(A.status,avenda);
Dados_cad ImoBit[guardQ];
FILE*fp=fopen("imobiliaria.txt","rb+");//abre um arquivo existente
if(fp==NULL)
{
    fp=fopen("imobiliaria.txt","wb+");//cria um arquivo
}
if (fp==NULL)
{
    printf("Deu Ruim");
    exit(1);
}
//variavel onde guardara a quantidade de vezes que cadastrara um dado "Vetor"
/*
printf("======================================================================\n");
printf("\nINFORME A QUANTIDADE DE IMOVEIS A SER CADASTRADO =  ");
scanf("%i",&quant_imv);
quant(quant_imv);
printf("\n======================================================================\n");*/

        //Variavel especiado do meu registro
        //Dados_cad dados_imov[quant_imv];
 //declaracoa da estrutura
  /*fp = fopen("imobiliaria.txt","wb"); // o arquvivo se chama imobiliaria e
  if ((fp = fopen("imobiliaria.txt","wb")) == NULL) {
 printf("\n Arquivo imobiliaria.txt não pode ser aberto");
}else{
  printf("Arquivo aberto com sucesso.");*/
quant();


do { //inicio do loop
  printf("\n-------Bem Vindo a ImoBit-------\n\nDesenvolvido por:\nLindson\n\n-----------MENU---------\n\n1 - CADASTRAR\n2 - PESQUISAR\n3 - LISTAR IMOVEIS A VENDA\n4 - ALTERAR PREÇO DE VENDA\n5 - LISTAR IMOVEIS POR TIPO\n6 - LISTAR IMOVEIS POR PADRAO\n7 - ALTERAR PREÇO DE NEGOCIAÇÃO\n8 - ENCERRAR\n\nDIGITE UMA OPÇÃO: ") ;
  scanf("%i",&op);
  switch (op) {

    case 1:
    cadastro();
    break;

    case 2:// pesquisar
      //pesquisar();
      printf("Digite o codigo do imovel: ");
      scanf("%d",&buscar);
      printf("\n\n======DADO DO IMOVEL======\n\n");
      for ( i = 0; i < guardQ; i++) {
        fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
      fread(&ImoBit[i], sizeof(Dados_cad), 1, fp);
      if (buscar == ImoBit[i].cod) {
          printf("\nCodigo: %d\nTipo: %s\nArea: %.2f\nArea Total: %.2f\nPadrao: %s\nPreco Sugerido: R$%.2f\n",ImoBit[i].cod,ImoBit[i].tipo,ImoBit[i].area_const,ImoBit[i].area_total,ImoBit[i].padrao,ImoBit[i].preco_surg);
            fread(&ImoBit, sizeof(Dados_cad), 1, fp);
            break;
}
        }
          break;

    case 3://listar todos os imoveis para venda
    /*
    fseek(fp,0,SEEK_SET);
    printf("Listas dos Produtos para Venda\n");
      while(fread(&A,sizeof(Dados_cad), 1, fp)) {
        if (!strcmp(A.status, "AV")) {//verificado se status e uma a AV informado no cadastro AV = a venda;
          MostrarDados(A);
        }
        else{
          printf("Codigo nao encontrado!\n");
        }
      }
      getchar();*/
        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;

    case 7:

        break;

  case 8:
   if (op == 8) {

     exit(0); //ENCERRANDO
     }
     break;

     default:
       printf("Opção Inválida\n");
     break;
   }//fim do swithc
} while(op != 0); //fim dowhile

fclose(fp);
  return 0;
}



/*
void cadastro(int quant)
{
    //Variavel especiado do meu registro
    //Dados_cad ImoBit[quant];

int codigo[50],i,op, guardaCod, k=0, achou = 0;

for (i = 0; i < quant; i++) {


 printf("\nInsira o novo código de identificação do imóvel:");
  scanf("%d", &guardaCod);
  achou = 0;
  if (ImoBit[i].cod ==  guardaCod)
  {
      achou = 1;
      printf("Codigo ja existe\n");
      break;
  }
if (achou == 1)break;
else{
  ImoBit[i].cod = guardaCod; //ATUALIZANDO O REGISTRO CODIOG COM O VALOR DA VARIAVEL INFORMADO ACIMA


    printf("\n Informe o tipo do imovel, C = Casa / A = Apartamento / L = Lote:");
        scanf("%s", &ImoBit[i].tipo);

        printf("\n Informe o bairro: ");
        scanf("%s", &ImoBit[i].bairro);
        fflush(stdin);


        printf("\n Informe a área construída em M²: ");
        scanf("%f", &ImoBit[i].area_const);
       fflush(stdin);

       printf("\n Informe a área total: ");
       scanf("%d", &ImoBit[i].area_total);
    fflush(stdin);

  printf("\n Qual o padrão de acabamento do imóvel (P = Popular / B = Bom / E = Excelente): ");
  scanf(" %s", &ImoBit[i].padrao);

  printf("\n Informe o preço sugerido (em reais) \n R$ ");
  scanf("%f", &ImoBit[i].preco_surg);
}
//  k++; //atualiza os index de k




        printf("\n Cadastro finalizado!");

}
}*/
