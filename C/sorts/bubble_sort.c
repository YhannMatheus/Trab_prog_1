#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct BenchmarkMetrics {
    double execution_time;
    int memory_usage;
    int comparisons;
    int swaps;
};

void bubble_sort(int array[], int size, struct BenchmarkMetrics *metrics) {
    bool swapped;
    int comparisons = 0;
    int swaps = 0;
    clock_t start_time = clock();

    do {
        swapped = false;
        for (int i = 0; i < size - 1; ++i) {
            if (array[i] > array[i + 1]) {
                // Realiza a troca
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swaps++;
                swapped = true;
            }
            comparisons++;
        }
    } while (swapped);

    clock_t end_time = clock();

    // Armazena as métricas
    metrics->execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    metrics->memory_usage = 0;  // Precisaria usar um profiler para medi-lo
    metrics->comparisons = comparisons;
    metrics->swaps = swaps;
}