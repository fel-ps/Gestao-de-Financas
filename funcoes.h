// ASSINATURA DAS FUNÇÕES

void invalido(void);

void obterDataAtual(char *data);

int verificarcpf(char *cpf, int tam);
void ler_cpf(char *cpf);

void ler_nome(char *name);
int validar_letras(char *nome, int tam);
int eh_letra_acentuada(char c);

void ler_telefone(char *telefone);
int validaTelefone(char *telefone);

int verif_csaldo(char* csaldo);
double* w_saldo(double*saldo);

int verifica_existe_cliente(char* cpf);