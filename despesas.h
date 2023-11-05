// STRUCT DE DESPESAS

typedef struct despesas {
    char cpf[12];
    char despesatext[500];
    double despesasaldo;
    int id;
    char data[11];
    char status;
} DESPESA;

// ASSINATURAS DESPESAS

void modulo_despesa(void);

void cadastrar_despesa(void);
void listar_despesas(void);
void editar_despesa(void);
void excluir_despesa(void);

DESPESA* preenche_despesa(void);
void exibe_despesas(DESPESA* ds, char *icpf);
void excluirDespesa(char* cpf, char* datainfo, int number);