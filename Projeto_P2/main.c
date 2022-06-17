#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "ArvoreRubroNegra.h"
#include "ArvoreAVL.h"

int menu();
void preencherArvoreAVL(FuncionarioAVL funcionario);
void preencherArvoreRubroNegra(FuncionarioRubroNegra funcionario);

int main()
{
    int m = menu();

    return 0;
}

int menu(){
    int opcao;

    printf("----------- Projeto Final ED2 -----------\n");
    printf("----- Desempenho AVL x Rubro-Negra ------\n\n");
    printf("Para comparar o tempo de desempenho do preenchimento das arvores selecione uma opcao.\n");
    printf("1 - Dados desordenados.\n");
    printf("2 - Dados previamente ordenados.\n\n");
    printf("Informe opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}

void preencherArvoreAVL(FuncionarioAVL funcionario) {
    struct timeval Tempo_antes, Tempo_depois;

    ArvoreRubroNegra *raiz;
    raiz = cria_ArvoreRubroNegra();

    FuncionarioRubroNegra func;
    func.id = 1;
    strncpy(func.nome, "Teste", 100);
    strncpy(func.empresa, "Teste", 100);
    func.idade = 22;
    strncpy(func.departamento, "Teste", 100);
    func.salario = 1000.00;

    gettimeofday(&Tempo_antes, NULL);
    insere_arvoreRubroNegra(raiz, func);
    gettimeofday(&Tempo_depois, NULL);

    return (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
                 (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
}

void preencherArvoreRubroNegra(FuncionarioRubroNegra funcionario) {
    struct timeval Tempo_antes, Tempo_depois;

    arvAVL *raiz;
    raiz = cria_arvAVL();

    FuncionarioAVL func;
    func.id = 1;
    strncpy(func.nome, "Teste", 100);
    strncpy(func.empresa, "Teste", 100);
    func.idade = 22;
    strncpy(func.departamento, "Teste", 100);
    func.salario = 1000.00;

    gettimeofday(&Tempo_antes, NULL);
    insere_arvAVL(raiz, func);
    gettimeofday(&Tempo_depois, NULL);

    return (Tempo_depois.tv_sec + Tempo_depois.tv_usec / 1000000.0) -
                 (Tempo_antes.tv_sec + Tempo_antes.tv_usec / 1000000.0);
}
