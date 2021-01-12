#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
lsindincins
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

int main()
{

    setlocale(LC_ALL,"portuguese");

    //inciando minhas variaveis para manipulação
    int i,j,k = 0, quant_imv = 0, opcao, achou = 0, pesquisarCod, guardaCod, contImov = 0;
    char aux_tipo[1],aux_padrao[1];

    //Variavel especiado do meu registro
    Dados_cad dados_imov[quant_imv];




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
    strcpy(dados_imov[k].status, avenda);

    fp = fopen("imobiliaria.txt","wb"); // o arquvivo se chama imobiliaria e
    if ((fp = fopen("imobiliaria.txt","wb")) == NULL) {
   printf("\n Arquivo imobiliaria.txt não pode ser aberto");
   }


    //variavel onde guardara a quantidade de vezes que cadastrara um dado "Vetor"
    printf("======================================================================\n");
    printf("\nINFORME A QUANTIDADE DE IMOVEIS A SER CADASTRADO =  ");
    scanf("%i",&quant_imv);
    printf("\n======================================================================\n");

while(opcao != 8){
    printf("\n-------Bem Vindo a ImoBit-------\n\nDesenvolvido por:\nLindson\n\n-----------MENU---------\n\n1 - CADASTRAR\n2 - PESQUISAR\n3 - LISTAR IMOVEIS A VENDA\n4 - ALTERAR PREÇO DE VENDA\n5 - LISTAR IMOVEIS POR TIPO\n6 - LISTAR IMOVEIS POR PADRAO\n7 - ALTERAR PREÇO DE NEGOCIAÇÃO\n8 - ENCERRAR\n\nDIGITE UMA OPÇÃO: ") ;

    scanf("%i",&opcao);
        switch(opcao)
        {
        case 1:




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

                  //    printf("\n Informe o status do imovel V = Vendido e AV = A Venda: ");
                  //   scanf("%s", &status[i]);


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
}//fim do else do cadastro
}//fim do else
                break;

      case 2: // Pesquisar por codigo um imovel
        printf("\nDigite o codigo de verificação do imóvel: ");
        scanf("%d",&pesquisarCod);
              for(i= 0; i < quant_imv; i++) {
                if (dados_imov[i].cod == pesquisarCod){
            printf("Codigo: %i",dados_imov[i].cod);
            printf("\nTipo C = Casa / A = Apartamento / L = Lote: %s", dados_imov[i].tipo);
            printf("\nBairro: %s", dados_imov[i].bairro);
            printf("\nÁrea construída em M²: %.2f", dados_imov[i].area_const);
            printf("\nÁrea Total: %.2f", dados_imov[i].area_total);
            printf("\nPadrão (P = Popular / B = Bom / E = Excelente): %s", dados_imov[i].padrao);
            printf("\nPreço Sugerido: R$ %.2f", dados_imov[i].preco_surg);
            printf("\nStatus do imovel V = Vendido e AV = A Venda: %s",dados_imov[i].status);
            printf("\npreço Negociado: R$ %.2f",negociado);
            printf("\n");
           break;
         }
         else
         printf("Codigo não encontrado\n");
        }//FIM DO FOR
   break;


   case 3: // listar imovies para venda
   printf("\nLista de Imóveis disponiveis para venda\n");
    for ( i = 0; i < quant_imv; i++) {
      if (!strcmp(dados_imov[i].status, "AV")) { //verificado se status e uma a AV informado no cadastro AV = a venda;
          printf("\n\n----------------------\n");
          printf("Codigo: %i\n",dados_imov[i].cod);
          printf("Tipo  (C = Casa / A = Apartamento / L = Lote) : %s\n",dados_imov[i].tipo);
          printf("Bairro: %s\n",dados_imov[i].bairro);
          printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
          printf("Área Total: %.2f\n",dados_imov[i].area_total);
          printf("Padrão (P = Popular / B = Bom / E = Excelente) : %s\n",dados_imov[i].padrao);
          printf("Preço Segerido: %.2f\n",dados_imov[i].preco_surg);
          printf("Status do imovel V = Vendido / AV = A Venda : %s\n",dados_imov[i].status);
          printf("preço Negociado: R$ %.2f",negociado);
      }
    }
   break;


   case 4: // Alterar preco sugerido do imovies
   printf("\n\n----------------------\n");
   printf("\nAlterar informações\n");
   printf("\nDigite o codigo de verificação do imóvel: ");
   fflush(stdin);
   scanf("%d", &pesquisarCod);
    printf("\n");
    printf("Dados do imovel encontrado: \n");
   for (i = 0; i < quant_imv; i++) {
   if (dados_imov[i].cod == pesquisarCod) {

    //primeiro bloco trazendo as informações do cadastro
    printf("Codigo: %i\n",dados_imov[i].cod);
    printf("Tipo  (C = Casa / A = Apartamento / L = Lote) : %s\n",dados_imov[i].tipo);
    printf("Bairro: %s\n",dados_imov[i].bairro);
    printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
    printf("Área Total: %.2f\n",dados_imov[i].area_total);
    printf("Padrão (P = Popular / B = Bom / E = Excelente) : %s\n",dados_imov[i].padrao);
    printf("Preço Segerido: %.2f\n",dados_imov[i].preco_surg);
    printf("Status do imovel (V = Vendido e AV = A Venda) : %s\n",dados_imov[i].status);
    printf("preço Negociado: R$ %.2f",negociado);

        printf("\n\nAltualize o preço de venda\n\n");


          printf("Codigo: %i\n",dados_imov[i].cod);
          printf("Tipo  (C = Casa / A = Apartamento / L = Lote) : %s\n",dados_imov[i].tipo);
          printf("Bairro: %s\n",dados_imov[i].bairro);
          printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
          printf("Área Total:%.2f\n",dados_imov[i].area_total);
          printf("Padrão (P = Popular / B = Bom / E = Excelente) : %s\n",dados_imov[i].status);
          printf("Preço Sugerido: ");
          scanf("%f",&sugerido);printf("\n");
          dados_imov[i].preco_surg = sugerido[i];  //atualizando o preço
          fflush(stdin);

            printf("\nAtualização concluida!\n\n");
            printf("\nDados atualizados:\n");

            printf("Codigo: %i\n",dados_imov[i].cod);
            printf("Tipo  (C = Casa / A = Apartamento / L = Lote): %s\n",dados_imov[i].tipo);
            printf("Bairro: %s\n",dados_imov[i].bairro);
            printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
            printf("Área Total: %.2f\n",dados_imov[i].area_total);
            printf("Padrão (P = Popular / B = Bom / E = Excelente): %s\n",dados_imov[i].padrao);
            printf("Preço Segerido: %.2f\n",dados_imov[i].preco_surg);
            printf("Status do imovel (V = Vendido e AV = A Venda): %s\n",dados_imov[i].status);
            printf("preço Negociado: R$ %.2f",negociado);
            printf("\n");
              }
              else{
              printf("Codigo não encontrado!\n");
              break;
            }
         }
      break;








   case 5:  //PESQUISAR POR TIPO A = Apartamento C = CASA  L = LOTE
      printf("\n\n----------------------\n");
      printf("\nInforme o tipo desejado: ");
        fflush(stdin);
        scanf("%s",&aux_tipo);
        printf("\n");
        printf("\nLista dos imóveis do tipo %s",aux_tipo);
        printf("\n");
        for (i = 0; i < quant_imv; i++) {
          if (!strcmp(dados_imov[i].tipo, aux_tipo)){
            printf("Codigo: %i\n",dados_imov[i].cod);
            printf("Tipo  (C = Casa / A = Apartamento / L = Lote): %s\n",dados_imov[i].tipo);
            printf("Bairro: %s\n",dados_imov[i].bairro);
            printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
            printf("Área Total: %.2f\n",dados_imov[i].area_total);
            printf("Padrão (P = Popular / B = Bom / E = Excelente): %s\n",dados_imov[i].padrao);
            printf("Preço Segerido: %.2f\n",dados_imov[i].preco_surg);
            printf("Status do imovel V = Vendido e AV = A Venda: %s\n",dados_imov[i].status);
            printf("preço Negociado: R$ %.2f\n",negociado);
    }//fim do if
   }//fim do for
   break;



   case 6: //PESQUISAR POR PADRAO B= BOM P = POPULAR E = Excelente
    printf("\n\n----------------------\n");
    printf("\nInforme o padrao de acabamento desejado: ");
        fflush(stdin);
        scanf("%s",&aux_padrao);
        printf("\n");
        printf("\nLista dos imóveis do padrão %s",aux_padrao);
        printf("\n");
        for (i = 0; i < quant_imv; i++) {
          if (!strcmp(dados_imov[i].padrao, aux_padrao)){
            printf("Codigo: %i\n",dados_imov[i].cod);
            printf("Tipo  (C = Casa / A = Apartamento / L = Lote): %s\n",dados_imov[i].tipo);
            printf("Bairro: %s\n",dados_imov[i].bairro);
            printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
            printf("Área Total: %.2f\n",dados_imov[i].area_total);
            printf("Padrão (P = Popular / B = Bom / E = Excelente): %s\n",dados_imov[i].padrao);
            printf("Preço Segerido: %.2f\n",dados_imov[i].preco_surg);
            printf("Status do imovel (V = Vendido e AV = A Venda): %s\n",dados_imov[i].status);
            printf("preço Negociado: R$ %.2f",negociado);
          }//fim do if
      }//fim do for
   break;


   case 7: //ALTERAR STATUS E PREÇO NEGOCIADO PARA UMA IMOVEL A SER VENDIDO
    printf("\n\n----------------------\n");
     printf("\nInforme o codigo do Imvovel a ser vendido: ");
        fflush(stdin);
        scanf("%i",&pesquisarCod);
        printf("\n");
        printf("\n");
        printf("Dados do imovel encontrado: \n");
        for (i = 0; i < quant_imv; i++) {
          if (dados_imov[i].cod == pesquisarCod)
          {
        printf("Codigo: %i\n",dados_imov[i].cod);
        printf("Tipo  (C = Casa / A = Apartamento / L = Lote): %s\n",dados_imov[i].tipo);
        printf("Bairro: %s\n",dados_imov[i].bairro);
        printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
        printf("Área Total: %.2f\n",dados_imov[i].area_total);
        printf("Padrão (P = Popular / B = Bom / E = Excelente): %s\n",dados_imov[i].padrao);
        printf("Preço Segerido: %.2f\n",dados_imov[i].preco_surg);
        printf("Status do imovel (V = Vendido e AV = A Venda): %s\n",dados_imov[i].status);
        printf("preço Negociado: R$ %.2f",negociado);

        printf("\n");
        printf("\nInforme o preço negociado da venda abaixo");
        printf("\n");

        printf("Codigo: %i\n",dados_imov[i].cod);
        printf("Tipo  (C = Casa / A = Apartamento / L = Lote) : %s\n",dados_imov[i].tipo);
        printf("Bairro: %s\n",dados_imov[i].bairro);
        printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
        printf("Área Total: %.2f\n",dados_imov[i].area_total);
        printf("Padrão (P = Popular / B = Bom / E = Excelente) : %s\n",dados_imov[i].padrao);
        printf("Preço Segerido: %.2f\n",dados_imov[i].preco_surg);
        strcpy(dados_imov[i].status, vendido);
        printf("Status do imovel (V = Vendido e AV = A Venda): %s\n",dados_imov[i].status);
      //  scanf("%s",&vendido); //INFORMANDO O STATUS V
         //ATUALIZANDO A VARIAVEL COM O NOVO VALOR INFORMADO NO REGISTRO
        printf("Digite o preço Negociado: R$ ");
        scanf("%f",&negociado);printf("\n");
        dados_imov[i].preco_negc = negociado;
        fflush(stdin);

        printf("\n Preço atualizado!\n\n");


          printf("\n===============================:Dados atualizados:===============================\n\n");
          printf("Codigo: %i\n",dados_imov[i].cod);
          printf("Tipo  (C = Casa / A = Apartamento / L = Lote): %s\n",dados_imov[i].tipo);
          printf("Bairro: %s\n",dados_imov[i].bairro);
          printf("Área construída em M²: %.2f\n",dados_imov[i].area_const);
          printf("Área Total: %.2f\n",dados_imov[i].area_total);
          printf("Padrão (P = Popular / B = Bom / E = Excelente): %s\n",dados_imov[i].padrao);
          printf("Preço Segerido: R$ %.2f\n",dados_imov[i].preco_surg);
          printf("Status do imovel (V = Vendido e AV = A Venda): %s\n",dados_imov[i].status);
          printf("preço Negociado: R$ %.2f",dados_imov[i].preco_negc);
          printf("\n===================================================================================\n");
      }
      else{
        printf("Codigo nao encontado\n");
        break;
      }
    }
   break;

   case 8:
    if (opcao == 8) {
      exit(0); //ENCERRANDO
      }

    default:
      printf("Opção Inválida\n");
    break;

    }//fechamento do switch

        getchar();

    }

    //finalizando while
    return 0;
}
