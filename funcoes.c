#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <wchar.h>
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

// TIME_ATUAL CHAT GPT
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
        wprintf(L"Informe o nome do cliente: "); scanf("%[^\n]%*c", name);
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
        wprintf(L"Digite um saldo inicial da sua poupança(0.00$): "); scanf("%[^\n]",csaldo);
        fflush(stdin);
        valido=verif_saldo(csaldo);
    } while (valido!=1);
    double vfloat=atof(csaldo);
    *saldo=vfloat;
    return saldo;
}




