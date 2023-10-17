// STRUCT DE DESPESAS

typedef struct despesas {
    char cpf[12];
    char despesatext[500];
} Despesa;

// ASSINATURAS DESPESAS

void modulo_despesa(void);

void cadastrar_despesa(void);
void pesquisar_despesa(void);
void editar_despesa(void);
void excluir_despesa(void);