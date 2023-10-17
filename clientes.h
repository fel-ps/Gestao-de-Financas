// STRUCT DE CLIENTES

typedef struct clientes {
    char cpf[12];
    char nome[51];
    char telefone[16];
} Cliente;

// ASSINATURAS CLIENTES

void modulo_cliente(void);

void cadastrar_cliente(void);
void pesquisar_cliente(void);
void editar_cliente(void);
void excluir_cliente(void);