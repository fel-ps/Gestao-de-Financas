// ASSINATURA DAS FUNÇÕES

void invalido(void);

struct tm obterDataAtual();

char verificarcpf(char *cpf, int tam);
void ler_cpf(char *cpf);

void ler_nome(char *name);
int validar_letras(char *nome, int tam);
int eh_letra_acentuada(char c);

void ler_telefone(char *telefone);
int validaTelefone(char *telefone);