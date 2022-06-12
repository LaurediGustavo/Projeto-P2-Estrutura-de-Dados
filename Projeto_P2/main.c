#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreRubroNegra.h"
#include "ArvoreAVL.h"

int main()
{
    ArvoreRubroNegra *raiz;
    raiz = cria_ArvoreRubroNegra();

    Funcionario func;
    func.id = 1;
    strncpy(func.nome, "Teste", 100);
    strncpy(func.empresa, "Teste", 100);
    func.idade = 22;
    strncpy(func.departamento, "Teste", 100);
    func.salario = 1000.00;

    int x = insere_arvoreRubroNegra(raiz, func);

    printf("%d", x);

    /*
    arvAVL *raiz;
    raiz = cria_arvAVL();

    FuncionarioAVL func;
    func.id = 1;
    strncpy(func.nome, "Teste", 100);
    strncpy(func.empresa, "Teste", 100);
    func.idade = 22;
    strncpy(func.departamento, "Teste", 100);
    func.salario = 1000.00;

    int x = insere_arvAVL(raiz, func);
    printf("%d", x);
    */

    return 0;
}
