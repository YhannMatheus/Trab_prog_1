#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../benchmark.h"

void bubble_sort(int array[], int size, struct BenchmarkMetrics *metrics) {
    bool troca;
    int comparacoes = 0;
    int trocas = 0;
    clock_t start_time = clock();

    do {
        troca = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                trocas++;
                troca = true;
            }
            comparacoes++;
        }
    } while (troca);

    clock_t end_time = clock();

    metrics->tempo_execucao = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    metrics->memoria = 0;
    metrics->comparacoes = comparacoes;
    metrics->trocas = trocas;
}