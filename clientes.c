#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>
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
                break;
            case '3':
                editar_cliente();
                break;
            case '4':
                excluir_cliente();
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

// EDITAR CLIENTE
// https://github.com/EL0ISA/CGmotel/blob/main/cliente.c#L146
void editar_cliente(void){

    char cpf[12];
    int opcc = -1;

    FILE* fp;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    system("clear||cls");
    wprintf(L"===============================\n");
    wprintf(L"======== Editar Cliente =======\n");
    wprintf(L"===============================\n");
    wprintf(L"\n");

    ler_cpf(cpf);
    if(verifica_existe_cliente(cpf) == 0) 
    {
        while(fread(cl,sizeof(Cliente), 1, fp)) 
        {
            if (strcmp(cl->cpf, cpf) == 0 && cl->status != 'x') 
            {
                do 
                {
                    system("clear||cls");
                    wprintf(L"\n");
                    wprintf(L"1 - Nome: %s\n", cl->nome);
                    wprintf(L"2 - Telefone: %s\n", cl->telefone);
                    wprintf(L"3 - Saldo($): %.2f\n", cl->saldo);
                    wprintf(L"0 - Finalizar alterações.\n");
                    wprintf(L"\n Campo que deseja editar: "); scanf("%d",&opcc);
                    fflush(stdin);
                    switch (opcc) 
                    {
                    case 1:
                        wprintf(L"\n");
                        ler_nome(cl->nome);
                        break;
                    case 2:
                        wprintf(L"\n");
                        ler_telefone(cl->telefone);
                        break;
                    case 3:
                        wprintf(L"\n");
                        w_saldo(&cl->saldo);
                        break;
                    case 0:
                        break;
                    default:
                        invalido();
                        break;
                    }
                    fseeko(fp, -1*(off_t)sizeof(Cliente), SEEK_CUR);
                    fwrite(cl, sizeof(Cliente), 1, fp);
                } while (opcc!=0);
                break;
            }
        }
    } else{
        wprintf(L"\nCliente não encontrado!");
    }
    free(cl);
    fclose(fp);

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}

void excluir_cliente(void){

    char ecpf[12];
    wprintf(L"\nDigite o CPF do cliente a ser excluido: "); scanf("%[^\n]%*c", ecpf);
    fflush(stdin);

    excluirClientePorCPF(ecpf);

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

    system("clear||cls");
    wprintf(L"\n||     CPF     ||                     CLIENTE                       ||   SALDO   ||    TELEFONE    ||");
    while(fread(cl,sizeof(Cliente), 1, fp)){
        if(!feof(fp)) {
            exibe_Clientes(cl);
        } 
    }

    wprintf(L"\n\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

    free(cl);
    fclose(fp);

}

void pesquisar_cliente(void){

    char pcpf[12];
    wprintf(L"\nDigite o CPF do cliente: "); scanf("%[^\n]%*c", pcpf);
    fflush(stdin);

    Cliente* clienteEncontrado = buscarClientePorCPF(pcpf);

    if (clienteEncontrado != NULL) {
        wprintf(L"\n= = = Cliente Encontrado = = =\n");
        wprintf(L"Nome: %s\n", clienteEncontrado->nome);
        wprintf(L"CPF: %s\n", clienteEncontrado->cpf);
        wprintf(L"Telefone: %s\n", clienteEncontrado->telefone);
        wprintf(L"Saldo(R$): %.2f\n", clienteEncontrado->saldo);
        free(clienteEncontrado);
    } else {
        wprintf(L"\nCliente não encontrado.");
    }

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);

}

// CADASTRA CLIENTE
Cliente* preenche_Cliente(void) 
{
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));

    bool v = true, f = false;
    char c;

    while(v) {
        ler_cpf(cl->cpf);
        c = verifica_existe_cliente(cl->cpf);
        if (c == 1) {
            v = f;  
        } else {
            wprintf(L"\nCliente já cadastrado com esse cpf!\n");
        }
    }
    ler_nome(cl->nome);
    ler_telefone(cl->telefone);
    w_saldo(&cl->saldo);
    cl->status = 'a';

    return cl;
}

// EXIBIR TODOS OS CLIENTES
void exibe_Clientes(Cliente* cl)
{
    //  ((cl == NULL) || (cl->status == 'x')) 
    if (cl->status != 'x') {
        wprintf(L"\n||-------------||---------------------------------------------------||-----------||----------------||");
        wprintf(L"\n|| %-12s|| %-50s|| %-10.2F|| %-15s||", cl->cpf, cl->nome, cl->saldo, cl->telefone);
        // wprintf(L"Saldo(R$): %.2f\n", cl->saldo);
    } else if(cl->status == 'x'){
        return;
    }
    else {
        wprintf(L"\n= = = Clientes Inexistentes = = =\n");
    }

}

// BUSCAR CLIENTE
Cliente* buscarClientePorCPF(char* cpf){

    FILE* fp;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    while (fread(cl, sizeof(Cliente), 1, fp)) {
        if ((strcmp(cl->cpf, cpf) == 0) && (cl->status != 'x')) {
            fclose(fp);
            return cl;
        }
    }

    fclose(fp);
    free(cl);
    return NULL;
}

// EXCLUIR CLIENTE
void excluirClientePorCPF(char* cpf) {

    FILE* fp;
    Cliente* cl;
    cl = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "rb+");
    if (fp == NULL) {
        wprintf(L"\nErro na criação");
        exit(1);
    }

    while (fread(cl, sizeof(Cliente), 1, fp)) {
        if (strcmp(cl->cpf, cpf) == 0) {
            cl->status = 'x';
            fseeko(fp, -1*(off_t)sizeof(Cliente), SEEK_CUR);
            fwrite(cl, sizeof(Cliente), 1, fp);
            wprintf(L"\nCliente excluído.\n");
            wprintf(L"\nTecle <ENTER> para continuar...\n");
            getchar();
            fflush(stdin);

            free(cl);
            fclose(fp);
            return;
        }
    }

    free(cl);
    fclose(fp);
    wprintf(L"\nCliente não encontrado.\n");

    wprintf(L"\nTecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}


    