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
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>
#include "clientes.h"
#include "receitas.h"
#include "despesas.h"
#include "relatorio.h"
#include "variaveis.h"
#include "funcoes.h"

// ASSINATURA DAS FUNÇÕES
void inicio(void);
void sobre(void);

// VARIÁVEIS
char opc; //global
char opc1;

// PROGRAMA PRINCIPAL
int main(void){

    setlocale(LC_CTYPE , "" );

    do {
        inicio();
        wprintf(L"\nDigite o que deseja fazer: "); scanf("%s", &opc1);
        getchar();
        fflush(stdin);
        
        switch (opc1) {
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
                getchar();
                fflush(stdin);
                break;
            case '0':
                wprintf(L"\nFIM");
                break;
            default:
                invalido();
                break;
        }
    } while (opc1!='0');

    return 0;
}

// FUNÇÕES
void inicio(void){
    system("clear||cls");
    wprintf(L"=========================      |  |    \n");
    wprintf(L"======= PyBanking =======    $$|$$|$$  \n");
    wprintf(L"=========================   $$ |  | $$ \n");
    wprintf(L"1 - Módulo de Clientes      $$ |  |    \n");
    wprintf(L"2 - Módulo de Receitas       $$|$$|$$  \n");
    wprintf(L"3 - Módulo de Despesas         |  | $$ \n");
    wprintf(L"4 - Módulo de Relatórios    $$ |  | $$ \n");
    wprintf(L"5 - Sobre                    $$|$$|$$  \n");
    wprintf(L"0 - Sair                       |  |    \n");
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
    wprintf(L"\nENDEREÇO GITHUB: https://github.com/FlaviusGorgonio/LinguaSolta.git \n");
    wprintf(L"ENDEREÇO REPLIT: https://replit.com/@aronsilvagm/GestaoDefinancas4#main.py \n");
    wprintf(L"ENDEREÇO GITHUB: https://github.com/mts-lucas/SIG-Finance \n");
    wprintf(L"\n");
    wprintf(L"\t\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
}
