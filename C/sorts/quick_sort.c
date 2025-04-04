#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../benchmark.h"

void swap(int* a, int* b, struct BenchmarkMetrics *metrics) {
    int temp = *a;
    *a = *b;
    *b = temp;
    metrics->trocas++;
}

int partition(int array[], int low, int high, struct BenchmarkMetrics *metrics) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        metrics->comparacoes++;
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j], metrics);
        }
    }

    swap(&array[i + 1], &array[high], metrics);
    return i + 1;
}

void quick_sort_with_benchmark(int array[], int size, struct BenchmarkMetrics *metrics) {
    metrics->comparacoes = 0;
    metrics->trocas = 0;
    metrics->memoria = 0;

    clock_t start_time = clock();

    int* stack = (int*)malloc(size * sizeof(int));
    if (stack == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        return;
    }

    int top = -1;
    stack[++top] = 0;
    stack[++top] = size - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];

        int pi = partition(array, low, high, metrics);

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }

    free(stack);
    clock_t end_time = clock();
    metrics->tempo_execucao = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}
