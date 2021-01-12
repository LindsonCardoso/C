#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct dados_cad
{
  int cod;
  char tipo[21];
  char bairro[21];
  char status[21];
  float area_const;
  float area_total;
  char padrao[21];
  float preco_surg;
  float preco_negc;
};

typedef struct dados_cad Dados_imov;

FILE*fp;


Dados_imov cadastro()
{
    Dados_imov A;

          printf("\nInsira o novo código de identificação do imóvel:");
          scanf("%d",&A.cod);
          fflush(stdin);

          printf("\n Informe o tipo do imovel, C = Casa / A = Apartamento / L = Lote: ");
          scanf("%s",&A.tipo);
          fflush(stdin);

          printf("\n Informe o bairro: ");
          scanf("%s",&A.bairro);
          fflush(stdin);

          printf("\n Informe a área construída em M²: ");
          scanf("%f",&A.area_const);
          fflush(stdin);

          printf("\n Informe a área total: ");
          scanf("%f",&A.area_total);
          fflush(stdin);

          printf("\n Qual o padrão de acabamento do imóvel (P = Popular / B = Bom / E = Excelente): ");
          scanf("%s",&A.padrao);
          printf("\n");

          strcpy(A.status,"A Venda"); // GRANVANDO O STATUS

          printf("\n Informe o preço sugerido (em reais) \n R$ ");
          scanf("%f",&A.preco_surg);

          A.preco_negc = 0.0;
          strcpy(A.status,"A Venda");

    return A;
}


void pesquisar(Dados_imov a)
{
      printf("\n====== IMOVEL ENCONTRADO: ======");
      printf("\nCodigo: %d\nTipo: %s\nBairro: %s\nArea Construida: %.2f\nArea Total: %.2f\nPadrao: %s\nStatus: %s\nPreco Sugerido: R$%.2f\nPreço Negociado: R$%.2f",a.cod,a.tipo,a.bairro,a.area_const,a.area_total,a.padrao,a.status,a.preco_surg,a.preco_negc);
      printf("\n\n");
}



int main()
{
    setlocale(LC_ALL,"Portuguese");

    Dados_imov A;
    int b, bus, achou = 0, contImov = 0, quant_imv = 0;
    float mudar, aux = 0;
    char e[2],tip[21],pad[21], vendido[] = "Vendido";

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
    do
    {

        printf("\n-------Bem Vindo a ImoBit-------\n\nDesenvolvido por:\nLindson\n\n-----------MENU---------\n\n1 - CADASTRAR\n2 - PESQUISAR\n3 - LISTAR IMOVEIS A VENDA\n4 - ALTERAR PREÇO DE VENDA\n5 - LISTAR IMOVEIS POR TIPO\n6 - LISTAR IMOVEIS POR PADRAO\n7 - ALTERAR PREÇO DE NEGOCIAÇÃO\n8 - ENCERRAR\n\nDIGITE UMA OPÇÃO: ") ;
        scanf("%d",&b);

        switch(b){
        case 1://inserir.

              A=cadastro();//Atribui a varivel de tipo struct o cadastro realizado na funcao
              fseek(fp,0,SEEK_END);//manda o ponteiro para o final do arquivo
              fwrite(&A,sizeof(Dados_imov),1,fp);//escreve no arquivo a variavel A do tamanho da struct uma vez em fp(o arquivo).
              printf("Cadastro realizado.");

        break;

        case 2://Pesquisa.

            fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
            printf("\nDigite um cod: ");
            scanf("%d",&bus);
            while(fread(&A,sizeof(Dados_imov),1,fp))//LER O ARQUIVO INTEIRO 1 POR 1 O TAMANHO DA STRUCT QUE DECLARA
                if(bus==A.cod)
                {
                    pesquisar(A);
                    break;
                }
        break;

        case 3://Listar a venda
  {
            fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
            while(fread(&A, sizeof(Dados_imov), 1, fp))
            {
                if(strcmp(A.status,"A Venda")==0)
                  pesquisar(A);
            }

  }
        break;

            case 4://4.	Atualização do preço de venda de um imóvel. Deve ser verificado se o código informado existe no cadastro.
{
              fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
              printf("\nDigite um cod: ");
              scanf("%d",&bus);
              achou = 0;
              while(fread(&A,sizeof(Dados_imov),1,fp)){//LER O ARQUIVO INTEIRO 1 POR 1 O TAMANHO DA STRUCT QUE DECLARA
                  if(bus==A.cod)
                  {
                      achou = 1;
                      printf("CODIGO ENCONTRADO!\n");
                      pesquisar(A);
                      printf("\n");
                      while (!feof(fp))
                      {//Varre o arquivo até o final
                        //fread(&A, sizeof(Dados_imov), 1, fp); //Lê os dados de imobiliaria e armazena em na variavel
                        if (A.preco_surg >= 0.0)
                        {
                        printf("\nPreço sugerido %.2f",A.preco_surg);
                        printf("\nAltere para o novo preço sugerido deste imovel: ");
                        printf("\n(em reais) \n R$ ");
                        scanf("%f",&mudar); //variavel para atualizar o novo preço
                        fflush(stdin); //Limpa o buffer do teclado
                        A.preco_surg = mudar; //atulizando o novo preco para o registro
                        fseek(fp,(-1)*sizeof(Dados_imov), SEEK_CUR);// //Leva o cursor para o início do registro(campo) atualmente em preco Sugerido
                        fwrite(&A,sizeof(Dados_imov),1,fp);//Grava os novos dados da alteracao
                        printf("Novo preço atualizado: %.2f",A.preco_surg);
                        break;
                          }
                      }
                    }
                    else if(achou == 0)
                    {
                      break;
                      printf("Codigo nao existe\n");
                    }
              }//fim do while
}
    break;

        case 5://	Listagem de todos os imóveis de um tipo.
{
                  fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
                  printf("\nInforme o tipo desejado:");
                  scanf("%s",tip);
                  fflush(stdin);
                  printf("\nLista dos imoveis do tipo %s\n ",tip);
                  do {
                        while(fread(&A,sizeof(Dados_imov),1,fp)){//LER O ARQUIVO INTEIRO 1 POR 1 O TAMANHO DA STRUCT QUE DECLARA
                              if(strcmp(tip,A.tipo)==0)
                              {
                                pesquisar(A);
                                break;
                              }
                      }
                  }while(!feof(fp));//enquanto nao chegar no final
}
            break;


            case 6://Litar por padrao de imoveis.
{
            fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
            printf("\nBuscar por um Padrao desejado:");
            scanf("%s",pad);
            fflush(stdin);
            printf("\nLista dos imoveis do Padrão %s\n ",pad);
            do{
              while(fread(&A,sizeof(Dados_imov),1,fp))
              {//LER O ARQUIVO INTEIRO 1 POR 1 O TAMANHO DA STRUCT QUE DECLARA
                  if(strcmp(pad,A.padrao)==0)
                  {
                      pesquisar(A);
                    break;
                  }
             }
            }while(!feof(fp));//enquanto nao chegar no final
}


              break;


            case 7: //7.Venda de um imóvel. Deve ser registrado o preço negociado. Deve ser verificado se o código informado existe no cadastro.
{
      fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
      printf("\nDigite um cod: ");
      scanf("%d",&bus);
      achou = 0;
      while(fread(&A,sizeof(Dados_imov),1,fp)){//LER O ARQUIVO INTEIRO 1 POR 1 O TAMANHO DA STRUCT QUE DECLARA
          if(bus==A.cod)
            {
                  achou = 1;
                  printf("CODIGO ENCONTRADO!\n");
                  pesquisar(A);
                  while (!feof(fp)) {//Varre o arquivo até o final
                    //fread(&A, sizeof(Dados_imov), 1, fp); //Lê os dados de imobiliaria e armazena em na variavel
                    if (A.preco_negc == 0){
                    printf("\nPreço sugerido %.2f",A.preco_negc);
                    strcpy(A.status,vendido);
                    printf("\nAltere para o novo preço sugerido deste imovel: ");
                    printf("\n(em reais) \n R$ ");
                    scanf("%f",&mudar); //variavel para atualizar o novo preço
                    fflush(stdin); //Limpa o buffer do teclado
                    A.preco_negc = mudar; //atulizando o novo preco para o registro
                    fseek(fp,(-1)*sizeof(Dados_imov), SEEK_CUR);//Leva o cursor para o início do registro(campo) atualmente em preco Sugerido
                    fwrite(&A,sizeof(Dados_imov),1,fp);//Grava os novos dados da alteracao
                    printf("Novo preço atualizado: %.2f",A.preco_negc);
                    break;
                                        }
                                      }
            }
            else if(achou == 0){
            printf("Codigo nao existe\n");
            break;
                    }
    }
}
            break;

            case 8: //finaliar processo
            exit(0);
            break;

            default:
            printf("Opção Nao encontrada");
            break;
        }//FIM DO SWITCH
} while(b!=0);

fclose(fp); //fechar  aquivo

return 0;


}//fim do int main
