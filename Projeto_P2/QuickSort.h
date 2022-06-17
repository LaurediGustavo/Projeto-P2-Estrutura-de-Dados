struct FUNCIONARIO {
    int id;
    char nome[100];
    int idade;
    char empresa[100];
    char departamento[100];
    float salario;
};
typedef struct FUNCIONARIO funcionario;

void quicksort(funcionario *funcionario, int e,int d);
