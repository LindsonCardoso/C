#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa {
    char nome [30];
    char cpf [15];
    int idade;
} Pessoa;



void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}

void ler_registros() {

    FILE *arquivo;
    Pessoa pessoa;

    arquivo = fopen("arquivo.bin", "rb");

    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo.\n");
        exit(1);
    }

    printf("\n ========== PESSOAS CADASTRADAS ==========\n\n");

    fread(&pessoa, sizeof(Pessoa), 1, arquivo);
    do {
        printf("\nNOME: %s\nCPF: %s\nIDADE: %d\n", pessoa.nome, pessoa.cpf, pessoa.idade);
        fread(&pessoa, sizeof(Pessoa), 1, arquivo);
    } while (!feof(arquivo)); // enquanto não chegar ao final do arquivo

    fclose(arquivo);
}

void gravar_registros() {

    FILE *arq;
    Pessoa pessoa;
    int i, n_reg;

    printf("\nQuantidade de registros para incluir: ");
    scanf("%d", &n_reg);
    limpa_linha();

    arq = fopen("arquivo.bin", "a+b"); // Leitura e escrita, colocando o ponteiro do arquivo no final deste, criando o arquivo caso o mesmo não exista.

    if (arq == NULL) {
        perror("Erro");
        exit(1);
    }
    for (i = 0; i < n_reg; i++) {

        printf("\nDigite o nome da pessoa: ");
        scanf("%[^\n]", pessoa.nome);
        limpa_linha();

        printf("Digite o cpf: ");
        scanf("%s", pessoa.cpf);
        limpa_linha();

        printf("Digite a idade: ");
        scanf("%d", &pessoa.idade);
        limpa_linha();

        fwrite(&pessoa, sizeof(Pessoa), 1, arq);
    }
    fclose(arq);
}

int main(void) {

    char opcao;

    do {
        gravar_registros();

        ler_registros();

        printf("\nDeseja continuar? [s/n]: ");
        scanf("%c", &opcao);
        limpa_linha();

    } while (opcao == 's');

    return 0;
}
