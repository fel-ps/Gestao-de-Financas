// STRUCT DE RECEITAS

typedef struct receitas {
    char cpf[12];
    //char receitatext[500];
} RECEITA;

// ASSINATURAS RECEITAS

void modulo_receita(void);

void cadastrar_receita(void);
void pesquisar_receita(void);
void editar_receita(void);
void excluir_receita(void);