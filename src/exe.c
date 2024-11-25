#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#include "trab.h"

int vencedor = -1;

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona(int vetor[], int low, int high)
{
    int pivo = vetor[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (vetor[j] < pivo)
        {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[high]);
    return (i + 1);
}

void quicksort(int vetor[], int low, int high)
{
    if (low < high)
    {
        int pi = particiona(vetor, low, high);

        quicksort(vetor, low, pi - 1);
        quicksort(vetor, pi + 1, high);
    }
}

void competicao(int num_threads)
{
    int vetor[10];

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 100;
    }

    printf("Vetor original: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    omp_set_num_threads(num_threads);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        #pragma omp critical
        {
            if (vencedor == -1)
            {
                printf("Thread %d está ordenando o vetor.\n", thread_id);
                quicksort(vetor, 0, 9);
                vencedor = thread_id;
            }
        }
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    printf("A thread vencedora foi: %d\n", vencedor);
}