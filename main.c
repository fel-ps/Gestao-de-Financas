///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///               Departamento de Computacao e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programacao                      ///
///              Projeto Sistema de Gestao de financas                      ///
///             Desenvolvido por Felipe Augusto (@fel-ps)                   ///
///////////////////////////////////////////////////////////////////////////////

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// ASSINATURA DAS FUNCOES
void inicio(void);
void cadastro_cliente(void);
void cadastro_receita(void);
void cadastro_despesa(void);
void relatorios(void);
void sobre(void);
void invalido(void);

// VARIAVEIS
int opc;
int start = 1;
int continuar;

// PROGRAMA PRINCIPAL
int main(){

    do {
        inicio();
        printf("\nDigite o que deseja fazer: "); scanf("%d", &opc);
        fflush(stdin);
        
        switch (opc) {
            case 1:
                cadastro_cliente();
                break;
            case 2:
                cadastro_receita();
                break;
            case 3:
                cadastro_despesa();
                break;
            case 4:
                relatorios();
                break;
            case 5:
                sobre();
                break;
            case 0:
                printf("\nFIM");
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
    printf("=========================      |  |    \n");
    printf("======= PyBanking =======    $$|$$|$$  \n");
    printf("=========================   $$ |  | $$ \n");
    printf("1 - Cadastro de Clientes    $$ |  |    \n");
    printf("2 - Cadastro de Receitas     $$|$$|$$  \n");
    printf("3 - Cadastro de Despesas       |  | $$ \n");
    printf("4 - Relatorios Mensais      $$ |  | $$ \n");
    printf("5 - Sobre                    $$|$$|$$  \n");
    printf("0 - Sair                       |  |    \n");
}

void cadastro_cliente(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("==================================\n");
        printf("====== Cadastro de Clientes ======\n");
        printf("==================================\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Pesquisar Cliente\n");
        printf("3 - Editar Cliente\n");
        printf("4 - Excluir Cliente\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%d", &opc);
        fflush(stdin);
        switch (opc) {
            case 1:
                // FUNCAO CADASTRAR
                break;
            case 2:
                // FUNCAO PESQUISAR
                break;
            case 3:
                // FUNCAO EDITAR
                break;
            case 4:
                // FUNCAO EXCLUIR
                break;
            case 0:
                continuar = 0;
                break;
            default:
                invalido();
                break;
        }
    }
}

void cadastro_receita(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("==================================\n");
        printf("====== Cadastro de Receitas ======\n");
        printf("==================================\n");
        printf("1 - Cadastrar Receita\n");
        printf("2 - Pesquisar Receita\n");
        printf("3 - Editar Receita\n");
        printf("4 - Excluir Receita\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%d", &opc);
        fflush(stdin);
        switch (opc) {
            case 1:
                // FUNCAO CADASTRAR
                break;
            case 2:
                // FUNCAO PESQUISAR
                break;
            case 3:
                // FUNCAO EDITAR
                break;
            case 4:
                // FUNCAO EXCLUIR
                break;
            case 0:
                continuar = 0;
                break;
            default:
                invalido();
                break;
        }
    }
}

void cadastro_despesa(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("==================================\n");
        printf("====== Cadastro de Despesas ======\n");
        printf("==================================\n");
        printf("1 - Cadastrar Despesa\n");
        printf("2 - Pesquisar Despesa\n");
        printf("3 - Editar Despesa\n");
        printf("4 - Excluir Despesa\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%d", &opc);
        fflush(stdin);
        switch (opc) {
            case 1:
                // FUNCAO CADASTRAR
                break;
            case 2:
                // FUNCAO PESQUISAR
                break;
            case 3:
                // FUNCAO EDITAR
                break;
            case 4:
                // FUNCAO EXCLUIR
                break;
            case 0:
                continuar = 0;
                break;
            default:
                invalido();
                break;
        }
    }
}

void relatorios(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("================================\n");
        printf("====== Relatorios Mensais ======\n");
        printf("================================\n");
        printf("1 - Relatar Saldo\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%d", &opc);
        fflush(stdin);
        switch (opc) {
            case 1:
                // FUNCAO Relatorios
                break;
            case 0:
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
    printf("========================================================================================================================\n");
    printf("======================================== Sistema de Gestao de financas Pessoais ========================================\n");
    printf("========================================================================================================================\n");
    printf("\nEsse projeto tem como objetivo a conclusao de DCT1106 - Programacao, ministrada por Flavius Gorgonio. Se trata de um sis");
    printf("\nstema de gestao de financas pessoais, que visa auxiliar os usuarios a gerenciarem melhor suas financas. Desenvolvido por");
    printf("\n@fel-ps, discente em Sistemas de Informacao - UFRN. Bases utilizadas para desenvolver o projeto estao localizadas nos se"); 
    printf("\nguintes enderecos:\n");
    printf("\nENDERECO GITHUB: https://github.com/FlaviusGorgonio/LinguaSolta.git\n");
    printf("ENDERECO REPLIT: https://replit.com/@aronsilvagm/GestaoDeFinancas4#main.py\n");
    printf("\n");
    printf("\t\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}

void invalido(void) {
    system("clear||cls");
    printf("OPCAO INVALIDA!");
    printf("\n");
    printf("Tecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}
    