// STRUCT DE RECEITAS

typedef struct receitas {
    char cpf[12];
    char receitatext[500];
    double receitasaldo;
    int id;
    char data[11];
    char status;
} RECEITA;

// ASSINATURAS RECEITAS

void modulo_receita(void);

void cadastrar_receita(void);
void editar_receita(void);
void excluir_receita(void);
void listar_receitas(void);

RECEITA* preenche_receita(void);
void exibe_receitas(RECEITA* rc, char *icpf);