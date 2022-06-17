#include <stdio.h>
#include <stdlib.h>
#include "ArvoreRubroNegra.h"

#define RED 1
#define BLACK 0

struct NO {
    FuncionarioRubroNegra funcionario;
    struct NO *esq;
    struct NO *dir;
    int cor;
};

ArvoreRubroNegra *cria_ArvoreRubroNegra(){
    ArvoreRubroNegra *raiz = (ArvoreRubroNegra*) malloc(sizeof(ArvoreRubroNegra));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int cor(struct NO *H) {
    if(H == NULL) {
        return BLACK;
    }
    else {
        return H->cor;
    }
}

void trocarCor(struct NO *H) {
    H->cor = !H->cor;

    if(H->esq != NULL) {
        H->esq->cor = !H->esq->cor;
    }

    if(H->dir != NULL) {
        H->dir->cor = !H->dir->cor;
    }
}

struct NO *rotacionaEsquerda(struct NO *A) {
    struct NO *B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO *rotacionaDireita(struct NO *A) {
    struct NO *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO *move2EsqRED(struct NO *H) {
    trocarCor(H);
    if(cor(H->dir->esq) == RED) {
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocarCor(H);
    }

    return H;
}

struct NO *move2DirRED(struct NO *H) {
    trocarCor(H);
    if(cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
        trocarCor(H);
    }

    return H;
}

struct NO *balancear(struct NO *H) {
    if(cor(H->dir) == RED) {
        H = rotacionaEsquerda(H);
    }

    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
    }

    if(cor(H->esq) == RED && cor(H->dir) == RED) {
        trocarCor(H);
    }

    return H;
}

struct NO *insereNO(struct NO *H, FuncionarioRubroNegra funcionario, int *resp) {
    if(H == NULL) {
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL) {
            *resp = 0;
            return NULL;
        }
        novo->funcionario = funcionario;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return NULL;
    }

    if(funcionario.id == H->funcionario.id) {
        *resp = 0;
    }
    else {
        if(funcionario.id < H->funcionario.id) {
            H->esq = insereNO(H->esq, funcionario, resp);
        }
        else {
            H->dir = insereNO(H->dir, funcionario, resp);
        }
    }
    if(cor(H->dir) == RED && cor(H->esq) == BLACK) {
        H = rotacionaEsquerda(H);
    }
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED) {
        trocarCor(H);
    }
    return H;
}

int insere_arvoreRubroNegra(ArvoreRubroNegra *raiz, FuncionarioRubroNegra funcionario) {
    int resp = 1;

    *raiz = insereNO(*raiz, funcionario, &resp);
    if((*raiz) != NULL) {
        (*raiz)->cor = BLACK;
    }

    return resp;
}

struct NO *removeMenor(struct NO *H) {
    if(H->esq == NULL) {
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK) {
        H = move2EsqRED(H);
    }
    H->esq = removeMenor(H->esq);
    return balancear(H);
}

struct NO *procuraMenor(struct NO *atual) {
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL) {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct NO *removeNO(struct NO *H, FuncionarioRubroNegra funcionario) {
    if(funcionario.id < H->funcionario.id) {
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK) {
            H = move2EsqRED(H);
        }
        H->esq = removeNO(H->esq, funcionario);
    }
    else {
        if(cor(H->esq) == RED) {
            H = rotacionaDireita(H);
        }
        if(funcionario.id == H->funcionario.id && (H->dir == NULL)) {
            free(H);
            return NULL;
        }
        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK) {
            H = move2DirRED(H);
        }
        if(funcionario.id == H->funcionario.id) {
            struct NO *x = procuraMenor(H->dir);
            H->funcionario.id = x->funcionario.id;
            H->dir = removeMenor(H->dir);
        }
        else {
            H->dir = removeNO(H->dir, funcionario);
        }
    }
    return balancear(H);
}

int consulta_arvoreLLRB(ArvoreRubroNegra *raiz, FuncionarioRubroNegra funcionario) {
    if(raiz == NULL) {
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL) {
        if(funcionario.id == atual->funcionario.id) {
            return 1;
        }
        if(funcionario.id > atual->funcionario.id) {
            atual = atual->dir;
        }
        else {
            atual = atual->esq;
        }
    }
    return 0;
}

int remove_arvoreRubroNegra(ArvoreRubroNegra *raiz, FuncionarioRubroNegra funcionario) {
    if(consulta_arvoreLLRB(raiz, funcionario)) {
        struct NO *H = *raiz;
        *raiz = removeNO(H, funcionario);
        if(*raiz != NULL) {
            (*raiz)->cor = BLACK;
        }
        return 1;
    }
    else {
        return 0;
    }
}
