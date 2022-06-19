#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "ArvoreRubroNegra.h"
#include "ArvoreAVL.h"

#define MAX_LINHA 20000
#define DELIMITADOR ";"
#define MASSA_DE_DADOS "massaDados.csv"

int menu();
void selecionarArvore(int value);
FILE* abrirArquivo(char arquivo[]);
double preencherArvoreAVL(arvAVL *raiz, char arquivo[]);
double preencherArvoreRubroNegra(ArvoreRubroNegra *raiz, char arquivo[]);
void exibirTempo(double tempoDesordenado, double tempoOrdenado);

int main()
{
    int value = menu();
    selecionarArvore(value);

    return 0;
}

int menu(){
    int opcao;

    printf("----------- Projeto Final ED2 -----------\n");
    printf("----- Desempenho AVL x Rubro-Negra ------\n\n");
    printf("Para comparar o tempo de desempenho do preenchimento das arvores selecione uma opcao.\n");
    printf("1 - Arvore AVL.\n");
    printf("2 - Arvore Rubro-Negra.\n\n");
    printf("Informe opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}

void selecionarArvore(int value) {
    switch(value) {
        case 1:
            {
                arvAVL *raiz;
                raiz = cria_arvAVL();

                double tempo1;
                tempo1 = preencherArvoreAVL(raiz, MASSA_DE_DADOS);
                exibirTempo(tempo1, 1.0);

                break;
            }
        case 2:
            {
                ArvoreRubroNegra *raiz;
                raiz = cria_ArvoreRubroNegra();

                double tempo1;
                tempo1 = preencherArvoreRubroNegra(raiz, MASSA_DE_DADOS);
                exibirTempo(tempo1, 1.0);

                break;
            }
        default:
            printf("Arvore nao encontrada");
    }
}

FILE* abrirArquivo(char arquivo[]) {
    FILE* file = fopen(arquivo, "r");
    if(file == NULL)
    {
        printf("Falha ao abrir o arquivo");
        return(1);
    }

    return file;
}

double preencherArvoreAVL(arvAVL *raiz, char arquivo[]) {
    struct timeval Tempo_antes, Tempo_depois;

    FILE* file = abrirArquivo(arquivo);

    char linha[MAX_LINHA];
    FuncionarioAVL func;
    gettimeofday(&Tempo_antes, NULL);
    while(fgets(linha, MAX_LINHA, file) != NULL)
    {
        func.id = atoi(strtok(linha, DELIMITADOR));
        strcpy(func.nome, strtok(NULL, DELIMITADOR));
        func.idade = atoi(strtok(NULL, DELIMITADOR));
        strcpy(func.empresa, strtok(NULL, DELIMITADOR));
        strcpy(func.departamento, strtok(NULL, DELIMITADOR));
        func.salario = atof(strtok(NULL, "\n"));

        insere_arvAVL(raiz, func);
    }
    gettimeofday(&Tempo_depois, NULL);

    fclose(file);

    return (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
             (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
}

double preencherArvoreRubroNegra(ArvoreRubroNegra *raiz, char arquivo[]) {
    struct timeval Tempo_antes, Tempo_depois;

    FILE* file = abrirArquivo(arquivo);

    char linha[MAX_LINHA];
    FuncionarioRubroNegra func;
    gettimeofday(&Tempo_antes, NULL);
    while(fgets(linha, MAX_LINHA, file) != NULL)
    {
        func.id = atoi(strtok(linha, DELIMITADOR));
        strcpy(func.nome, strtok(NULL, DELIMITADOR));
        func.idade = atoi(strtok(NULL, DELIMITADOR));
        strcpy(func.empresa, strtok(NULL, DELIMITADOR));
        strcpy(func.departamento, strtok(NULL, DELIMITADOR));
        func.salario = atof(strtok(NULL, "\n"));

        insere_arvoreRubroNegra(raiz, func);
    }
    gettimeofday(&Tempo_depois, NULL);

    fclose(file);

    return (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
             (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
}

void exibirTempo(double tempoDesordenado, double tempoOrdenado) {
    printf("Tempo de insercao dos dados desordenados: \n");
    printf("Tempo: %f\n\n", tempoDesordenado);
    printf("Tempo de insercao dos dados ordenados: \n");
    printf("Tempo: %f\n\n", tempoOrdenado);
}
