#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../benchmark.h"

int partition(int array[], int low, int high, struct BenchmarkMetrics *metrics) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        metrics->comparacoes++;
        if (array[j] < pivot) {
            i++;
            
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            metrics->trocas++;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    metrics->trocas++;

    return i + 1;
}

void quick_sort(int array[], int low, int high, struct BenchmarkMetrics *metrics) {
    if (low < high) {
        int pi = partition(array, low, high, metrics);

        quick_sort(array, low, pi - 1, metrics);
        quick_sort(array, pi + 1, high, metrics);
    }
}

void quick_sort_with_benchmark(int array[], int size, struct BenchmarkMetrics *metrics) {
    metrics->comparacoes = 0;
    metrics->trocas = 0;
    metrics->memoria = 0; 

    clock_t start_time = clock();
    quick_sort(array, 0, size - 1, metrics);
    clock_t end_time = clock();

    metrics->tempo_execucao = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}