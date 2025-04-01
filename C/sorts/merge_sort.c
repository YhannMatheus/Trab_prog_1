#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../benchmark.h"

void merge(int array[], int left, int mid, int right, struct BenchmarkMetrics *metrics) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    metrics->memoria += (n1 + n2) * sizeof(int);
    
    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        metrics->comparacoes++;
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int array[], int left, int right, struct BenchmarkMetrics *metrics) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(array, left, mid, metrics);
        merge_sort(array, mid + 1, right, metrics);

        merge(array, left, mid, right, metrics);
    }
}

void merge_sort_with_benchmark(int array[], int size, struct BenchmarkMetrics *metrics) {
    metrics->comparacoes = 0;
    metrics->trocas = 0; 
    metrics->memoria = 0;

    clock_t start_time = clock();
    merge_sort(array, 0, size - 1, metrics);
    clock_t end_time = clock();

    metrics->tempo_execucao = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}