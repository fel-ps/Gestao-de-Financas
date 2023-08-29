///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serid�                     ///
///               Departamento de Computa��o e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programa��o                      ///
///              Projeto Sistema de Gest�o de finan�as                      ///
///             Desenvolvido por Felipe Augusto (@fel-ps)                   ///
///////////////////////////////////////////////////////////////////////////////

// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ASSINATURA DAS FUN��ES
void inicio(void);
void cadastro_cliente(void);
void cadastro_receita(void);
void cadastro_despesa(void);
void relatorios(void);
void sobre(void);

// VARI�VEIS
char opc[2];
int start = 1;
int continuar;

// PROGRAMA PRINCIPAL
int main(){

    setlocale(LC_ALL,"Portuguese_Brazil");

    while (start == 1){
        inicio();
        printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc);
        fflush(stdin);
        
        switch (opc[0]) { // ACESSANDO O PRIMEIRO CARACTERE DA STRING
            case '1':
                cadastro_cliente();
                break;
            case '2':
                cadastro_receita();
                break;
            case '3':
                cadastro_despesa();
                break;
            case '4':
                relatorios();
                break;
            case '5':
                sobre();
                break;
            case '0':
                printf("\nFIM");
                start = 0;
                break;
            default:
                system("clear||cls");
                printf("OP��O INV�LIDA!");
                printf("\n");
                system("pause");
                break;
        }
    }

    return 0;
}

// FUN��ES
void inicio(void){
    system("clear||cls");
    printf("=========================\n");
    printf("======= PyBanking =======\n");
    printf("=========================\n");
    printf("1 - Cadastro de Clientes\n");
    printf("2 - Cadastro de Receitas\n");
    printf("3 - Cadastro de Despesas\n");
    printf("4 - Relat�rios Mensais\n");
    printf("5 - Sobre\n");
    printf("0 - Sair\n");
}

void cadastro_cliente(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("====================================\n");
        printf("======= Cadastro de Clientes =======\n");
        printf("====================================\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Pesquisar Cliente\n");
        printf("3 - Editar Cliente\n");
        printf("4 - Excluir Cliente\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc);
        fflush(stdin);
        switch (opc[0]) { // ACESSANDO O PRIMEIRO CARACTERE DA STRING
            case '1':
                // FUN��O CADASTRAR
                break;
            case '2':
                // FUN��O PESQUISAR
                break;
            case '3':
                // FUN��O EDITAR
                break;
            case '4':
                // FUN��O EXCLUIR
                break;
            case '0':
                continuar = 0;
                break;
            default:
                system("clear||cls");
                printf("OP��O INV�LIDA!");
                printf("\n");
                system("pause");
                break;
        }
    }
}

void cadastro_receita(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("====================================\n");
        printf("======= Cadastro de Receitas =======\n");
        printf("====================================\n");
        printf("1 - Cadastrar Receita\n");
        printf("2 - Pesquisar Receita\n");
        printf("3 - Editar Receita\n");
        printf("4 - Excluir Receita\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc);
        fflush(stdin);
        switch (opc[0]) { // ACESSANDO O PRIMEIRO CARACTERE DA STRING
            case '1':
                // FUN��O CADASTRAR
                break;
            case '2':
                // FUN��O PESQUISAR
                break;
            case '3':
                // FUN��O EDITAR
                break;
            case '4':
                // FUN��O EXCLUIR
                break;
            case '0':
                continuar = 0;
                break;
            default:
                system("clear||cls");
                printf("OP��O INV�LIDA!");
                printf("\n");
                system("pause");
                break;
        }
    }
}

void cadastro_despesa(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("====================================\n");
        printf("======= Cadastro de Despesas =======\n");
        printf("====================================\n");
        printf("1 - Cadastrar Despesa\n");
        printf("2 - Pesquisar Despesa\n");
        printf("3 - Editar Despesa\n");
        printf("4 - Excluir Despesa\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc);
        fflush(stdin);
        switch (opc[0]) { // ACESSANDO O PRIMEIRO CARACTERE DA STRING
            case '1':
                // FUN��O CADASTRAR
                break;
            case '2':
                // FUN��O PESQUISAR
                break;
            case '3':
                // FUN��O EDITAR
                break;
            case '4':
                // FUN��O EXCLUIR
                break;
            case '0':
                continuar = 0;
                break;
            default:
                system("clear||cls");
                printf("OP��O INV�LIDA!");
                printf("\n");
                system("pause");
                break;
        }
    }
}

void relatorios(void){
    continuar = 1;
    while (continuar == 1){
        system("clear||cls");
        printf("==================================\n");
        printf("======= Relat�rios Mensais =======\n");
        printf("==================================\n");
        printf("1 - Relatar Saldo\n");
        printf("0 - Sair\n");
        printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc);
        fflush(stdin);
        switch (opc[0]) { // ACESSANDO O PRIMEIRO CARACTERE DA STRING
            case '1':
                // FUN��O RELAT�RIOS
                break;
            case '0':
                continuar = 0;
                break;
            default:
                system("clear||cls");
                printf("OP��O INV�LIDA!");
                printf("\n");
                system("pause");
                break;
        }
    }
}

void sobre(void) {
    system("clear||cls");
    printf("========================================================================================================================\n");
    printf("======================================== Sistema de Gest�o de Finan�as Pessoais ========================================\n");
    printf("========================================================================================================================\n");
    printf("\nEsse projeto tem como objetivo a conclus�o de DCT1106 - Programa��o, ministrada por Flavius Gorg�nio. Se trata de um sis");
    printf("\nstema de gest�o de finan�as pessoais, que visa auxiliar os usu�rios a gerenciarem melhor suas finan�as. Desenvolvido por");
    printf("\n@fel-ps, discente em Sistemas de Informa��o - UFRN. Bases utilizadas para desenvolver o projeto est�o localizadas nos se"); 
    printf("\nguintes endere�os:\n");
    printf("\nENDERE�O GITHUB: https://github.com/FlaviusGorgonio/LinguaSolta.git\n");
    printf("ENDERE�O REPLIT: https://replit.com/@aronsilvagm/GestaoDeFinancas4#main.py\n");
    printf("\n");
    system("pause");
}


    