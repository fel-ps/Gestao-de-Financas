///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serid�                     ///
///               Departamento de Computa��o e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programa��o                      ///
///              Projeto Sistema de Gest�o de Finan�as                      ///
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

// PROGRAMA PRINCIPAL
int main(){

    setlocale(LC_ALL,"Portuguese_Brazil");

    inicio();
    printf("\nDigite o que deseja fazer: "); scanf("%1s", &opc);
    
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
            printf("FIM");
            break;
        default:
            printf("OP��O INV�LIDA!");
            break;
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
    system("clear||cls");
    printf("====================================\n");
    printf("======= Cadastro de Clientes =======\n");
    printf("====================================\n");
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Pesquisar Cliente\n");
    printf("3 - Editar Cliente\n");
    printf("4 - Excluir Cliente\n");
    printf("0 - Sair\n");
}

void cadastro_receita(void){
    system("clear||cls");
    printf("====================================\n");
    printf("======= Cadastro de Receitas =======\n");
    printf("====================================\n");
    printf("1 - Cadastrar Receita\n");
    printf("2 - Pesquisar Receita\n");
    printf("3 - Editar Receita\n");
    printf("4 - Excluir Receita\n");
    printf("0 - Sair\n");
}

void cadastro_despesa(void){
    system("clear||cls");
    printf("====================================\n");
    printf("======= Cadastro de Despesas =======\n");
    printf("====================================\n");
    printf("1 - Cadastrar Despesa\n");
    printf("2 - Pesquisar Despesa\n");
    printf("3 - Editar Despesa\n");
    printf("4 - Excluir Despesa\n");
    printf("0 - Sair\n");
}

void relatorios(void){
    system("clear||cls");
    printf("==================================\n");
    printf("======= Relat�rios Mensais =======\n");
    printf("==================================\n");
    printf("1 - Relatar Saldo\n");
    printf("0 - Sair\n");
}

void sobre(void) {
    system("clear||cls");
    printf("========================================================================================================================\n");
    printf("======================================= Sistema de Gest�o de Finan�as Pessoais =======================================\n");
    printf("========================================================================================================================\n");
    printf("\nEsse projeto tem como objetivo a conclus�o de DCT1106 - Programa��o, ministrada por Flavius Gorg�nio.");
    printf("\nSe trata de um sistema de gest�o de finan�as pessoais, que visa auxiliar os usu�rios a gerenciarem me-");
    printf("\nlhor suas finan�as. Desenvolvido por @fel-ps, discente em Sistemas de Informa��o - UFRN. Bases utilizadas"); 
    printf("\npara desenvolver o projeto est�o localizadas nos seguintes endere�os: ENDERE�O GITHUB: https://github.com/FlaviusGorgonio/LinguaSolta.git | ENDERE�O REPLIT: https://replit.com/@aronsilvagm/GestaoDeFinancas4#main.py\n");
    printf("\n");
    printf("\t\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); // Aguarda o usu�rio pressionar Enter
}


    