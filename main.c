#include <stdio.h>
#include <stdlib.h>

// FUNÇÕES
void inicio(void);
void cadastro_cliente(void);
void cadastro_receita(void);
void cadastro_despesa(void);
void relatorios(void);
void sobre(void);

// VARIÁVEIS
char opc[1]= "";

// PROGRAMA PRINCIPAL
int main(){

    sobre();
    inicio();
    printf("\nDigite o que deseja fazer: "); scanf("%s", &opc);

    printf("%s", &opc);
}

void inicio(void){
    system("clear||cls");
    printf("=========================\n");
    printf("======= PyBanking =======\n");
    printf("=========================\n");
    printf("1 - Cadastro de Clientes\n");
    printf("2 - Cadastro de Receitas\n");
    printf("3 - Cadastro de Despesas\n");
    printf("4 - Relatórios Mensais\n");
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
    printf("======= Relatórios Mensais =======\n");
    printf("==================================\n");
    printf("1 - Relatar Saldo\n");
    printf("0 - Sair\n");
}

void sobre(void) {
    system("clear||cls");
    printf("======================================================================\n");
    printf("=============== Sistema de Gestão de Finanças Pessoais ===============\n");
    printf("======================================================================\n");
    printf("\nEsse projeto tem como objetivo a conclusão de DCT1106 - Programação, ministrada por Flavius Gorgônio");
    printf("\nse trata de um sistema de gestão de finança pessoal, que visa conter todos os requisitos necessarios para ser avaliado");
    printf("\ndesenvolvido por @fel-ps, discente em Bacharelado em Sistemas de Informação - UFRN CERES."); 
    printf("\nbase utilizada para desenvolver o projeto está localizada nesse endereço github: https://github.com/FlaviusGorgonio/LinguaSolta.git\n");
    getchar(); // Aguarda o usuário pressionar Enter
}


    