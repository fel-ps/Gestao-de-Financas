#include <stdio.h>
#include <stdlib.h>

// INVÁLIDO
void invalido(void) {
    system("clear||cls");
    wprintf(L"OPÇÃO INVALIDA!");
    wprintf(L"\n");
    wprintf(L"Tecle <ENTER> para continuar...\n");
    getchar();
    fflush(stdin);
}