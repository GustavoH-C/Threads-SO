#include <stdio.h>
#include "trab.h"


int main() {
    int num_threads = 4;

    competicao(num_threads);

    printf("A thread que chegou foi a thread %d.\n", vencedor);

    return 0;
}
