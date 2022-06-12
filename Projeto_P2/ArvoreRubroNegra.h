typedef struct FUNCIONARIO {
    int id;
    char nome[100];
    int idade;
    char empresa[100];
    char departamento[100];
    float salario;
} Funcionario;

//typedef struct FUNCIONARIO Funcionario;

typedef struct NO *ArvoreRubroNegra;

ArvoreRubroNegra *cria_ArvoreRubroNegra();

int insere_arvoreRubroNegra(ArvoreRubroNegra *raiz, Funcionario funcionario);

int remove_arvoreRubroNegra(ArvoreRubroNegra *raiz, Funcionario funcionario);
