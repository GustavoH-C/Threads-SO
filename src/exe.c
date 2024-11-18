
#include <stdio.h>
#include <omp.h>
#include "../include/trab.h"

void competicao(int conta, int vencedor, int tamanho){
int num_threads = 4;  // Podemos alterar para mais ou menos threads
    omp_set_num_threads(num_threads);


    // Região paralela
    #pragma omp parallel
    {
        while (1) {
            #pragma omp critical
            {
                if (conta < tamanho) {
                    conta++;

                    printf("Thread %d contou até %d\n", omp_get_thread_num(), conta);

                    if (conta == tamanho && vencedor == -1) {
                        vencedor = omp_get_thread_num();
                    }
                }
            }

            if (conta >= tamanho) {
                break;
            }
        }
    }


    printf("A thread vencedora foi a número %d.\n", vencedor);

}
