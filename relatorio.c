#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "variaveis.h"
#include "funcoes.h"

// VARIÁVEIS

void modulo_relatorio(void){
    do {
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
                break;
            default:
                invalido();
                break;
        }
    } while (opc!='0');
}

// FUNÇÃO DE RELATÓRIO
void relatar_saldo(void){
    system("clear||cls");
    wprintf(L"================================\n");
    wprintf(L"====== Relatório de Saldo ======\n");
    wprintf(L"================================\n");
}