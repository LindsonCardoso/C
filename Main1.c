#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//definido minha estrutura do struct

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

Dados_cad ImoBit[9999999];


FILE*fp;


void DigitarImoves()
{
  int codigo;
  char tipo[21][21];
  char status[21][21];
  char bairro[21][21];
  float area[50];
  int total [50];
  char padrao[21][21];
  float sugerido[50];
  float negociado = 0;;
  char avenda[] = "AV";
  char vendido[] = "V";
//  strcpy(ImoBit.status, avenda);

  int i, op, guardaCod, achou = 0;
{
    for ( i = 0; i < 50 ; i++) {

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
       scanf("%s", &tipo[i]);

      printf("\n Informe o bairro: ");
      scanf("%s", &bairro[i]);
      fflush(stdin);


       printf("\n Informe a área construí,da em M²: ");
      scanf("%f", &area[i]);
       fflush(stdin);

       printf("\n Informe a área total: ");
       scanf("%d", &total[i]);


       printf("\n Qual o padrão de acabamento do imóvel (P = Popular / B = Bom / E = Excelente): ");
      scanf(" %s", &padrao[i]);

       printf("\n Informe o preço sugerido (em reais) \n R$ ");
     scanf("%f", &sugerido[i]);



                strcpy(ImoBit[i].tipo,tipo[i]);
                strcpy(ImoBit[i].bairro,bairro[i]);
                ImoBit[i].area_const = area[i];
                ImoBit[i].area_total = total[i];
                ImoBit[i].preco_surg = sugerido[i];
                strcpy(ImoBit[i].padrao, padrao[i]);

       printf("\n Se deseja realizar outro cadastro digite 4. \n \n *Para finalizar digite qualquer valor: ");
       scanf("%d", &op);


        if (op!=4){
               break;
          //  fwrite(&A,sizeof(A), 1, fp);
                    }
}


}
}
if (op!=4)
 {
     printf("\n Cadastro finalizado!");
    //fwrite(&A,sizeof(A), 1, fp);
 }


}

void pesquisar()
{ ImoBit;
    int op;
    system("cls");
    int pesquisaid,i;
    do
    {      fseek(fp,0,SEEK_SET);
        printf("\nDigite o numero de identificação do imovel:");
        scanf("%d", &pesquisaid);
        for ( i = 0; i < 50; i++) {
           while(fread(&ImoBit,sizeof(ImoBit), 1, fp)) {
             if (pesquisaid == ImoBit[i].cod) {
                printf("Codigo: %i",ImoBit[i].cod);
      printf("\nTipo C = Casa / A = Apartamento / L = Lote: %s", ImoBit[i].tipo);
      printf("\nBairro: %s", ImoBit[i].bairro);
      printf("\nÁrea construída em M²: %.2f", ImoBit[i].area_const);
      printf("\nÁrea Total: %.2f", ImoBit[i].area_total);
      printf("\nPadrão (P = Popular / B = Bom / E = Excelente): %s", ImoBit[i].padrao);
      printf("\nPreço Sugerido: R$ %.2f", ImoBit[i].preco_surg);
      //printf("\nStatus do imovel V = Vendido e AV = A Venda: %s",ImoBit[i].status);
      //printf("\npreço Negociado: R$ %.2f",negociado);
      printf("\n");
             }
             else{
               printf("Codigo nao encontrado!\n");
             }
           }
           getchar();
    }
    /*    for(i=0;i<50;i++)
        {
            if (ImoBit[i].cod == pesquisaid)
            {
              printf("Codigo: %i",ImoBit[i].cod);
printf("\nTipo C = Casa / A = Apartamento / L = Lote: %s", ImoBit[i].tipo);
printf("\nBairro: %s", ImoBit[i].bairro);
printf("\nÁrea construída em M²: %.2f", ImoBit[i].area_const);
printf("\nÁrea Total: %.2f", ImoBit[i].area_total);
printf("\nPadrão (P = Popular / B = Bom / E = Excelente): %s", ImoBit[i].padrao);
printf("\nPreço Sugerido: R$ %.2f", ImoBit[i].preco_surg);
//printf("\nStatus do imovel V = Vendido e AV = A Venda: %s",ImoBit[i].status);
//printf("\npreço Negociado: R$ %.2f",negociado);
printf("\n");*/

        printf("\nDigite 1 para pesquisar novamente: ");
        scanf("%d", &op);
    }
    while(op==1);

}

void MostrarDados(Dados_cad a){

  printf("\nCodigo: %d",a.cod);
  printf("\nTipo: %s",a.tipo);
  printf("\nBairro: %s",a.bairro);
  printf("\nArea construída: %.2f",a.area_const);
  printf("\nArea total: %.2f",a.area_total);
  printf("\npadrao de acabamento: %s",a.padrao);
  printf("\nPreço Sugerido: %.2f",a.preco_surg);

}





void lista();
void listatipo();
void listapadrao();
void alterar();
void excluir();


int  main()
{
	setlocale(LC_ALL,"portuguese");
  Dados_cad A;
  int op, quant_imv = 0, buscar;
  int contImov = 0;

  //variavel onde guardara a quantidade de vezes que cadastrara um dado "Vetor"
  printf("======================================================================\n");
  printf("\nINFORME A QUANTIDADE DE IMOVEIS A SER CADASTRADO =  ");
  scanf("%i",&quant_imv);
  printf("\n======================================================================\n");

        //Variavel especiado do meu registro
        //Dados_cad dados_imov[quant_imv];
 //declaracoa da estrutura
  /*fp = fopen("imobiliaria.txt","wb"); // o arquvivo se chama imobiliaria e
  if ((fp = fopen("imobiliaria.txt","wb")) == NULL) {
 printf("\n Arquivo imobiliaria.txt não pode ser aberto");
}else{
  printf("Arquivo aberto com sucesso.");*/


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

do { //inicio do loop
  printf("\n-------Bem Vindo a ImoBit-------\n\nDesenvolvido por:\nLindson\n\n-----------MENU---------\n\n1 - CADASTRAR\n2 - PESQUISAR\n3 - LISTAR IMOVEIS A VENDA\n4 - ALTERAR PREÇO DE VENDA\n5 - LISTAR IMOVEIS POR TIPO\n6 - LISTAR IMOVEIS POR PADRAO\n7 - ALTERAR PREÇO DE NEGOCIAÇÃO\n8 - ENCERRAR\n\nDIGITE UMA OPÇÃO: ") ;
  scanf("%i",&op);
  switch (op) {

    case 1:
    //  cadastro();
     DigitarImoves();
     fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo
     fwrite(&A,sizeof(Dados_cad),1,fp);//escreve no arquivo a variavel A do tamanho da struct uma vez em fp(o arquivo).

    break;

    case 2: // pesquisar
    pesquisar();

    /*  fseek(fp,0,SEEK_SET);
      printf("\nInforme o codigo do imovel: ");
      scanf("%i",&buscar);
        while(fread(&A,sizeof(Dados_cad), 1, fp)) {
          if (buscar == A.cod) {
            MostrarDados(A);
          }
          else{
            printf("Codigo nao encontrado!\n");
          }
        }
        getchar();*/
                break;


    case 3://listar todos os imoveis para venda

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
