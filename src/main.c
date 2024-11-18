#include <stdio.h>
#include <omp.h>
#include "../include/trab.h"

int conta = 0;
int vencedor = -1;
int tamanho = 0;

int main() {
    
    printf("Digite até quanto as threads devem contar\n");
    scanf("%d", &tamanho);
    competicao(conta, vencedor, tamanho);
    return 0;
}
