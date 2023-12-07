#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
#include <stdbool.h>
#include "funcoes.h"
#include "clientes.h"

// INVÁLIDO
void invalido(void) {
    system("clear||cls");
    wprintf(L"OPÇÃO INVALIDA!");
    wprintf(L"\n");
    wprintf(L"Tecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}

// TIME_ATUAL (CHAT GPT)
void obterDataAtual(char *data) {
    time_t t;
    struct tm *info;

    time(&t);
    info = localtime(&t);

    strftime(data, 11, "%d/%m/%Y", info);

    //char dataAtual[11];
    //obterDataAtual(dataAtual);
    //wprintf(L"Data atual: %s\n", dataAtual);
}

// FUNÇÃO PEGA MÊS ATUAL
void obterMesAtual(char *mes) {
    time_t t;
    struct tm *info;

    time(&t);
    info = localtime(&t);

    // Use o campo tm_mon + 1 para obter o mês (1 a 12)
    snprintf(mes, 3, "%02d", info->tm_mon + 1);
}

// VALIDAR CPF https://github.com/mts-lucas
int verificarcpf(char *cpf, int tam)
{
    if (tam < 11)
    {
        return 0;
    }

    if (tam == 11)
    {
        int calc = 0;
        int mult = 10;
        int dv1, dv2;
        for (int i = 0; i < 9; i++)
        {
            calc = calc + ((cpf[i] - 48) * mult);
            mult = mult - 1;
            dv1 = (calc * 10) % 11;
        }
        mult = 11;
        calc = 0;
        for (int i = 0; i < 10; i++)
        {
            calc = calc + ((cpf[i] - 48) * mult);
            mult = mult - 1;
            dv2 = (calc * 10) % 11;
        }

        if ((dv1 == 10))
        {
            dv1 = 0;
        }
        if ((dv2 == 10))
        {
            dv2 = 0;
        }

        char dc1, dc2;
        dc1 = dv1 + '0';
        dc2 = dv2 + '0';

        if ((dv1 == 10 && cpf[tam - 2] != '0') || (dv2 == 10 && cpf[tam - 1] != '0'))
        {
            return 0;
        }
        else if ((cpf[tam - 2] != dc1) || (cpf[tam - 1] != dc2))
        {
            return 0;
        }
    }

    else if (tam > 11)
    {
        return 0;
    }

    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (i > 0 && cpf[i] == cpf[i - 1])
        {
            cont = cont + 1;

            if (cont == tam - 1)
            {
                return 0;
            }
        }
    }

    return 1;
}

// LER CPF https://github.com/mts-lucas
void ler_cpf(char *cpf)
{
    int tam;
    do
    {
        wprintf(L"Informe o CPF do cliente(apenas números): "); scanf("%[^\n]%*c", cpf);
        fflush(stdin);
        tam = strlen(cpf);
    } while (!(verificarcpf(cpf, tam)));
}

// LER NOME
void ler_nome(char *name)
{
    int tam;
    do
    {
        wprintf(L"Informe o nome do cliente(sem acentuação): "); scanf("%[^\n]%*c", name);
        fflush(stdin);
        tam = strlen(name);
    } while (!(validar_letras(name, tam)));
}

// VALIDAR LETRAS https://github.com/mts-lucas
int validar_letras(char *nome, int tam)
{
    if (nome[0] == ' '){
        return 0;
    }
     for (int i = 0; i <= (tam - 1); i++) {
        if (nome[i] == ' ') {
            // Se for um espaço em branco, continue verificando os próximos caracteres
            continue;
        }
        
        if (((nome[i] <= 'z') && (nome[i] >= 'A')) || (eh_letra_acentuada(nome[i]))) {
            if (((nome[i] > 'Z') && (nome[i] < 'a')) && (!(eh_letra_acentuada(nome[i])))) {
                return 0;
            }
        } 
        else {
            return 0;
        }
    }
    return 1;
}

// ACEITA LETRA ACENTUADA https://github.com/Claudio-Arauj
int eh_letra_acentuada(char c)
{ // Claúdio Pereira e Matheus Diniz Fernandes
  char letras_acentuadas[] = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç";
  int tam = strlen(letras_acentuadas);
    
  for (int j = 0; j < tam; j++) {
    if (c == letras_acentuadas[j]) {
      return 1; // Caso encontre validação retorna True
    }
  }
    
  return 0;
}

// LER TELEFONE GPT
void ler_telefone(char *telefone) 
{
    do
    {
        wprintf(L"Digite um número de telefone(Ex: (99)91234-5678): "); scanf("%[^\n]%*c", telefone);
        fflush(stdin);
    } while (!(validaTelefone(telefone)));
}

// VALIDA TELEFONE GPT
int validaTelefone(char *telefone) // Apenas Brasil
{
    // Remove o '\n' do final da string (se existir)
    if (telefone[strlen(telefone) - 1] == '\n')
    {
        telefone[strlen(telefone) - 1] = '\0';
    }

    int tamanho = strlen(telefone);
    int digitos = 0;
    

    // Verifica se o tamanho está dentro do intervalo [min, max]
    int min = 10;
    int max = 15;
    if (tamanho < min || tamanho > max) 
    {
        return 0; // Tamanho inválido
    }

    if (telefone[0] != '(' || telefone[3] != ')')
    {
        return 0; // Parênteses do DDD na posição incorreta
    }

    // Verifica se todos os caracteres são dígitos ou separadores
    for (int i = 0; i < tamanho; i++) 
    {
        if (i != 0 && i != 3)
        {
            if (!isdigit(telefone[i]) && (telefone[i] != ' ') && (telefone[i] != '-'))
            {
                return 0;
            }
        }
        if ((telefone[i] >= '0' && telefone[i] <= '9') || (telefone[i] != ' ' && telefone[i] != '-')) 
        {
            digitos++;
        }
    }

    // Verifica se há pelo menos o número mínimo de dígitos
    if (digitos < min) 
    {
        return 0;
    }

    return 1;
}

// VALIDA PREÇO https://github.com/EL0ISA/CGmotel/blob/main/uteis.c
int verif_saldo(char* csaldo){
    int tam=strlen(csaldo);
    int contPonto=0,ponto=0, p_ponto=0;
    if(tam>20){
        return 0;
    }
    for (int i = 0; i < tam; i++)
    {
        if(!isdigit(csaldo[i]) && csaldo[i]!='.'){
            return 0;
        }
        if(ispunct(csaldo[i])){
            contPonto++;
        }
    }
    if(contPonto>1){
        return 0;
    } else if(contPonto==1){
        for (int i = 0; csaldo[i]!='.'; i++){
            ponto++;
        }
        for (int i = (ponto); i<tam; i++){
            p_ponto++;
        }
        if((p_ponto-1)>2){
            return 0;
        }
    }
   return 1; 
}

// VALIDA PREÇO https://github.com/EL0ISA/CGmotel/blob/main/uteis.c
double* w_saldo(double*saldo){
    int valido;
    char csaldo[20];
    do
    {
        wprintf(L"Digite um saldo(0.00$): "); scanf("%[^\n]",csaldo);
        getchar();
        fflush(stdin);
        valido=verif_saldo(csaldo);
    } while (valido!=1);
    double vfloat=atof(csaldo);
    *saldo=vfloat;
    return saldo;
}

// Verificar se o cliente já existe no sistema
// Evitar cpf iguais https://github.com/Matheusdnf/projeto_horarios_de_aula/blob/main/aluno.c
int verifica_existe_cliente(char* cpf){

    FILE* fp;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    while(fread(cl, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cl->cpf, cpf) == 0) && (cl->status != 'x')) {
            return 0;
        }
    }

    fclose(fp);
    free(cl);
    return 1;
}

// GERADOR DE CHAVE (CHATGPT)
void gerarCodigoAleatorio(char *id) 
{
    // Inicializa a semente do gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Gera o primeiro caractere (letra maiúscula)
    id[0] = 'A' + (rand() % 26);

    // Gera o segundo caractere (número de 0 a 9)
    id[1] = '0' + (rand() % 10);

    // Gera os três caracteres restantes
    for (int i = 2; i < 6; ++i) {
        id[i] = gerarCaractereAleatorio();
    }

    // Adiciona o caractere nulo no final para formar uma string válida
    id[5] = '\0';
}

// GERADOR DE CHAVE (CHATGPT)
char gerarCaractereAleatorio() 
{
    // Gera um número aleatório entre 0 e 35
    int randNum = rand() % 36;

    // Converte o número para o caractere correspondente
    if (randNum < 10) {
        return '0' + randNum; // Números de 0 a 9
    } else {
        return 'A' + (randNum - 10); // Letras maiúsculas de A a Z
    }
}

// LER DATA (CHAT GPT)
void lerData(char* data) {
    // Lê a data e valida até que uma entrada válida seja fornecida
    do {
        wprintf(L"Digite a data no formato dd/mm/aaaa: "); scanf("%10s", data);
        getchar();
        fflush(stdin);
    } while (!validarData(data));
}

// VALIDA DATA (CHAT GPT)
int validarData(const char *data) {
    // Verifica se a data está no formato dd/mm/aaaa
    int dia, mes, ano;
    if (sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano) == 3) {
        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12) {
            // Lógica básica para verificar se o ano é válido (pode precisar de regras adicionais)
            if (ano >= 1900 && ano <= 2100) {
                return true;
            }
        }
    }
    return false;
}