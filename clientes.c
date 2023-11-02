#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include "clientes.h"
#include "variaveis.h"
#include "funcoes.h"

// VARIÁVEIS

void modulo_cliente(void){
    do {
        system("clear||cls");
        wprintf(L"==================================\n");
        wprintf(L"======= Módulo de Clientes =======\n");
        wprintf(L"==================================\n");
        wprintf(L"1 - Cadastrar Cliente\n");
        wprintf(L"2 - Pesquisar Cliente\n");
        wprintf(L"3 - Editar Cliente\n");
        wprintf(L"4 - Excluir Cliente\n");
        wprintf(L"5 - Listar Clientes\n");
        wprintf(L"0 - Sair\n");
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc);
        getchar();
        fflush(stdin);
        switch (opc) {
            case '1':
                cadastrar_cliente();
                break;
            case '2':
                pesquisar_cliente();
                getchar();
                fflush(stdin);
                break;
            case '3':
                editar_cliente();
                getchar();
                fflush(stdin);
                break;
            case '4':
                excluir_cliente();
                getchar();
                fflush(stdin);
                break;
            case '5':
                listar_clientes();
            case '0':
                break;
            default:
                invalido();
                break;
        }
    } while (opc!='0');
}

// FUNÇÕES DE CLIENTES
void cadastrar_cliente(void){

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Cadastrar Cliente ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");

    FILE* fp;
    Cliente* cliente;
    fp = fopen("clientes.dat","ab");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    cliente = preenche_Cliente();
    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
    free(cliente);

    wprintf(L"\nCliente Cadastrado!");
    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

}

void pesquisar_cliente(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"====== Pesquisar Cliente ======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
}

void editar_cliente(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Cliente =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
}

void excluir_cliente(void){

    char cpf[12];

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======= Excluir Cliente =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");
    ler_cpf(cpf);
}

void listar_clientes(void){

    FILE* fp;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    int c = 1;
    while(fread(cl,sizeof(Cliente), 1, fp)){
        exibe_Clientes(cl, c);
        c++;
    }

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

    free(cl);
    fclose(fp);


    
}

// CADASTRA CLIENTE
Cliente* preenche_Cliente(void) 
{
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));

    ler_nome(cl->nome);
    ler_cpf(cl->cpf);
    ler_telefone(cl->telefone);
    w_saldo(&cl->saldo);
    cl->status = 'a';

    return cl;
}

// EXIBIR TODOS OS CLIENTES
void exibe_Clientes(Cliente* cl, int c)
{

    if ((cl == NULL) || (cl->status == 'x')) {
        wprintf(L"\n= = = Clientes Inexistentes = = =\n");
    } 
    else 
    {
        wprintf(L"\n= = = Cliente %d = = =\n", c);
        wprintf(L"Nome: %s\n", cl->nome);
        wprintf(L"CPF: %s\n", cl->cpf);
        wprintf(L"Telefone: %s\n", cl->telefone);
        wprintf(L"Saldo: %.2f\n", cl->saldo);
    }

}
