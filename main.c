#include <stdio.h>
#include <stdlib.h>

#define inicio "=========================\n======= PyBanking =======\n=========================\n1 - Cadastro de Usuário\n2 - Cadastro de Receita\n3 - Cadastro de Despesa\n4 - Relatório Mensal\n5 - Sobre"

char opc[1]= "";

int main(){

    printf("\n%s\n", inicio);
    printf("\nDigite o que deseja fazer: "); scanf("%s", &opc);

    printf("%s", &opc);
}
