typedef struct FUNCIONARIORUBRONEGRA {
    int id;
    char nome[100];
    int idade;
    char empresa[100];
    char departamento[100];
    float salario;
} FuncionarioRubroNegra;

typedef struct NO *ArvoreRubroNegra;

ArvoreRubroNegra *cria_ArvoreRubroNegra();

int insere_arvoreRubroNegra(ArvoreRubroNegra *raiz, FuncionarioRubroNegra funcionario);

int remove_arvoreRubroNegra(ArvoreRubroNegra *raiz, FuncionarioRubroNegra funcionario);
