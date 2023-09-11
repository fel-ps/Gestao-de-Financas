///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///              Projeto Sistema de Gestão de finanças                      ///
///             Desenvolvido por Felipe Augusto (@fel-ps)                   ///
///////////////////////////////////////////////////////////////////////////////

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ASSINATURA DAS FUNCOES
void inicio(void);
void modulo_cliente(void);
void modulo_receita(void);
void modulo_despesa(void);
void modulo_relatorio(void);
void sobre(void);
void invalido(void);

void cadastrar_cliente(void);
void pesquisar_cliente(void);
void editar_cliente(void);
void esxcluir_cliente(void);

void cadastrar_receita(void);
void pesquisar_receita(void);
void editar_receita(void);
void esxcluir_receita(void);

void cadastrar_despesa(void);
void pesquisar_despesa(void);
void editar_despesa(void);
void esxcluir_despesa(void);

void relatar_saldo(void);

// VARIAVEIS
char opc;
int start = 1;
int continuar;

// PROGRAMA PRINCIPAL
int main(){

    setlocale(LC_CTYPE , "" );

    do {
        inicio();
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        fflush(stdin);
        
        switch (opc) {
            case '1':
                modulo_cliente();
                break;
            case '2':
                modulo_receita();
                break;
            case '3':
                modulo_despesa();
                break;
            case '4':
                modulo_relatorio();
                break;
            case '5':
                sobre();
                break;
            case '0':
                wprintf(L"\nFIM");
                start = 0;
                break;
            default:
                invalido();
                break;
        }
    } while (start == 1);
}

// FUNCOES
void inicio(void){
    system("clear||cls");
    wprintf(L"=========================      |  |    \n");
    wprintf(L"======= PyBanking =======    $$|$$|$$  \n");
    wprintf(L"=========================   $$ |  | $$ \n");
    wprintf(L"1 - Cadastro de Clientes    $$ |  |    \n");
    wprintf(L"2 - Cadastro de Receitas     $$|$$|$$  \n");
    wprintf(L"3 - Cadastro de Despesas       |  | $$ \n");
    wprintf(L"4 - Relatórios Mensais      $$ |  | $$ \n");
    wprintf(L"5 - Sobre                    $$|$$|$$  \n");
    wprintf(L"0 - Sair                       |  |    \n");
}

void modulo_cliente(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        wprintf(L"==================================\n");
        wprintf(L"====== Cadastro de Clientes ======\n");
        wprintf(L"==================================\n");
        wprintf(L"1 - Cadastrar Cliente\n");
        wprintf(L"2 - Pesquisar Cliente\n");
        wprintf(L"3 - Editar Cliente\n");
        wprintf(L"4 - Excluir Cliente\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        fflush(stdin);
        switch (opc) {
            case '1':
                cadastrar_cliente();
                getchar();
                break;
            case '2':
                // FUNÇÃO PESQUISAR
                break;
            case '3':
                // FUNÇÃO EDITAR
                break;
            case '4':
                // FUNÇÃO EXCLUIR
                break;
            case '0':
                continuar = 0;
                break;
            default:
                invalido();
                break;
        }
    }
}

void modulo_receita(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        wprintf(L"==================================\n");
        wprintf(L"====== Cadastro de Receitas ======\n");
        wprintf(L"==================================\n");
        wprintf(L"1 - Cadastrar Receita\n");
        wprintf(L"2 - Pesquisar Receita\n");
        wprintf(L"3 - Editar Receita\n");
        wprintf(L"4 - Excluir Receita\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        fflush(stdin);
        switch (opc) {
            case '1':
                // FUNÇÃO CADASTRAR
                break;
            case '2':
                // FUNÇÃO PESQUISAR
                break;
            case '3':
                // FUNÇÃO EDITAR
                break;
            case '4':
                // FUNÇÃO EXCLUIR
                break;
            case '0':
                continuar = 0;
                break;
            default:
                invalido();
                break;
        }
    }
}

void modulo_despesa(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        wprintf(L"==================================\n");
        wprintf(L"====== Cadastro de Despesas ======\n");
        wprintf(L"==================================\n");
        wprintf(L"1 - Cadastrar Despesa\n");
        wprintf(L"2 - Pesquisar Despesa\n");
        wprintf(L"3 - Editar Despesa\n");
        wprintf(L"4 - Excluir Despesa\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        fflush(stdin);
        switch (opc) {
            case '1':
                // FUNÇÃO CADASTRAR
                break;
            case '2':
                // FUNÇÃO PESQUISAR
                break;
            case '3':
                // FUNÇÃO EDITAR
                break;
            case '4':
                // FUNÇÃO EXCLUIR
                break;
            case '0':
                continuar = 0;
                break;
            default:
                invalido();
                break;
        }
    }
}

void modulo_relatorio(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        wprintf(L"================================\n");
        wprintf(L"====== Relatórios Mensais ======\n");
        wprintf(L"================================\n");
        wprintf(L"1 - Relatar Saldo\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        fflush(stdin);
        switch (opc) {
            case '1':
                // FUNÇÃO Relatórios
                break;
            case '0':
                continuar = 0;
                break;
            default:
                invalido();
                break;
        }
    }
}

void sobre(void) {
    system("clear||cls");
    wprintf(L"========================================================================================================================\n");
    wprintf(L"======================================== Sistema de Gestão de finanças Pessoais ========================================\n");
    wprintf(L"========================================================================================================================\n");
    wprintf(L"\nEsse projeto tem como objetivo a conclusão de DCT1106 - Programação, ministrada por Flavius Gorgônio. Se trata de um sis");
    wprintf(L"\nstema de Gestão de finanças pessoais, que visa auxiliar os usuários a gerenciarem melhor suas finanças. Desenvolvido por");
    wprintf(L"\n@fel-ps, discente em Sistemas de Informação - UFRN. Bases utilizadas para desenvolver o projeto estao localizadas nos se"); 
    wprintf(L"\nguintes endereços:\n");
    wprintf(L"\nENDEREÇO GITHUB: https://github.com/FlaviusGorgonio/LinguaSolta.git\n");
    wprintf(L"ENDEREÇO REPLIT: https://replit.com/@aronsilvagm/GestaoDefinancas4#main.py\n");
    wprintf(L"\n");
    wprintf(L"\t\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}

void invalido(void) {
    system("clear||cls");
    wprintf(L"OPÇÃO INVALIDA!");
    wprintf(L"\n");
    wprintf(L"Tecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}

void cadastrar_cliente(void){
    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Cadastrar Cliente ======\n");
    wprintf(L"===============================\n");
}
