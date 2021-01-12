#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100
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

Dados_imov A[MAX];



//variavel global para receber um valor
  int quant_imv = 0;
  int guardQ = 0;

//func
  void quant(){
    printf("\nINFORME A QUANTIDADE DE IMOVEIS A SER CADASTRADO =  ");
    scanf("%i",&quant_imv);
    guardQ += quant_imv;
  }


Dados_imov cadastro()
{
   A;
    int guardaCod, achou = 0,i, k = 0;

          printf("\nInsira o novo código de identificação do imóvel:");
          scanf("%d", &guardaCod);
          achou = 0;
        for( i=0; i<guardQ; i++){
          if (A[i].cod == guardaCod)
          {
              achou = 1;
              printf("Codigo ja existe\n");

          }
        }
        if (achou == 1);
        else{

          A[k].cod = guardaCod;

    fflush(stdin);

    printf("\n Informe o tipo do imovel, C = Casa / A = Apartamento / L = Lote: ");
    scanf("%s",A[k].tipo);
    fflush(stdin);

    printf("\n Informe o bairro: ");
    scanf("%s",&A[k].bairro);
    fflush(stdin);

    printf("\n Informe a área construída em M²: ");
    scanf("%f",&A[k].area_const);
    fflush(stdin);

    printf("\n Informe a área total: ");
    scanf("%f",&A[k].area_total);
    fflush(stdin);

    printf("\n Qual o padrão de acabamento do imóvel (P = Popular / B = Bom / E = Excelente): ");
    scanf("%s",A[k].padrao);
    printf("\n");

    strcpy(A[k].status,"A Venda"); // GRANVANDO O STATUS

    printf("\n Informe o preço sugerido (em reais) \n R$ ");
    scanf("%f",&A[k].preco_surg);

    A[k].preco_negc = 0.0;
    strcpy(A[k].status,"A Venda");

k++;
}
return A[MAX];

}


void pesquisar(Dados_imov a)
{
printf("\n====== IMOVEL ENCONTRADO: ======");
printf("\nCodigo: %d\nTipo: %s\nBairro: %s\nArea Construida: %.2f\nArea Total: %.2f\nPadrao: %s\nStatus: %s\nPreco Sugerido: R$%.2f\nPreço Negociado: R$%.2f",a.cod,a.tipo,a.bairro,a.area_const,a.area_total,a.padrao,a.status,a.preco_surg,a.preco_negc);
    printf("\n\n");
}

int main()
{
quant();
    setlocale(LC_ALL,"Portuguese");
    Dados_imov A[MAX];
    int b, bus, achou = 0,contImov= 0;
    float mudar, aux = 0;
    char e[2],tip[21],pad[21];
    char vendido[] = "Vendido";
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

        case 1:
        //inserir.

      if (contImov == quant_imv) { // verificado se ja foram cadatrado imoveis
            printf("Imoveis ja encontrados, Não é possivel cadastrar novamente");
            break;
          }else{
            A[MAX]=cadastro();//Atribui a varivel de tipo struct o cadastro realizado na funcao
            fseek(fp,0,SEEK_END);//manda o ponteiro para o final do arquivo
            fwrite(&A[MAX],sizeof(Dados_imov),1,fp);//escreve no arquivo a variavel A do tamanho da struct uma vez em fp(o arquivo).
            printf("Cadastro realizado.");
            contImov++;
            }
            //sleep(2);
        break;

        case 2://Pesquisa.

            fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
            printf("\nDigite um cod: ");
            scanf("%d",&bus);
            while(fread(&A[MAX],sizeof(Dados_imov),1,fp))//LER O ARQUIVO INTEIRO 1 POR 1 O TAMANHO DA STRUCT QUE DECLARA
                if(bus==A[MAX].cod)
                {
                    pesquisar(A[MAX]);
                    system("pause");
                    break;

                }
        break;

        case 3://Listar.
{
  fseek(fp,0,SEEK_SET);//manda o ponteiro para o inicio do arquivo.
      while(fread(&A[MAX], sizeof(Dados_imov), 1, fp)){
      if(strcmp(A[MAX].status,"A Venda")==0)
    pesquisar(A[MAX]);
      //} while (!feof(fp)); // enquanto não chegar ao final do arquivo
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
