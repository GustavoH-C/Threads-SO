#include <stdio.h>
#include <omp.h>
#include "trab.h"

int contador = 0;
int vencedor = -1;

void competicao(int num_threads, int max)
{

    omp_set_num_threads(num_threads);

#pragma omp parallel
    {
        while (1)
        {
#pragma omp critical
            {
                if (contador < max)
                {
                    contador++;

                    printf("Thread %d contou até %d\n", omp_get_thread_num(), contador);

                    if (contador == max && vencedor == -1)
                    {
                        vencedor = omp_get_thread_num();
                    }
                }
            }

            if (contador >= max)
            {
                break;
            }
        }
    }
}
