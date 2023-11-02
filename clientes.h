// STRUCT DE CLIENTES

typedef struct cliente {
    char cpf[12];
    char nome[51];
    char telefone[16];
    double saldo;
    char status;
} Cliente;

// ASSINATURAS CLIENTES

void modulo_cliente(void);

void cadastrar_cliente(void);
void pesquisar_cliente(void);
void editar_cliente(void);
void excluir_cliente(void);
void listar_clientes(void);

Cliente* preenche_Cliente(void);
void exibe_Clientes(Cliente*, int c);
Cliente* buscarClientePorCPF(char* cpf);