#include <stdio.h>
#include <stdlib.h>
#include "sorts/bubble_sort.c"
#include "sorts/merge_sort.c"
#include "sorts/quick_sort.c"
#include "list_generator.c"

int main() {
    int tamanhos[] = {1000, 10000, 100000, 1000000}; // Tamanhos de entrada
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    struct BenchmarkMetrics metrics;

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int limite_superior = 1000000; // Limite superior para os números aleatórios
        int *array = (int *)malloc(n * sizeof(int)); // Aloca dinamicamente o array

        if (array == NULL) {
            printf("Erro ao alocar memória para o array de tamanho %d.\n", n);
            return 1;
        }

        printf("\n--- Tamanho do array: %d ---\n", n);

        // Gera o array aleatório e testa o Bubble Sort
        gerar_array_aleatorio(array, n, limite_superior);
        printf("\nBubble Sort:\n");
        bubble_sort(array, n, &metrics);
        printf("Tempo: %f s, Comparações: %d, Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);

        // Gera novamente o array aleatório e testa o Merge Sort
        gerar_array_aleatorio(array, n, limite_superior);
        printf("\nMerge Sort:\n");
        merge_sort_with_benchmark(array, n, &metrics);
        printf("Tempo: %f s, Comparações: %d, Memória: %d bytes\n", metrics.tempo_execucao, metrics.comparacoes, metrics.memoria);

        // Gera novamente o array aleatório e testa o Quick Sort
        gerar_array_aleatorio(array, n, limite_superior);
        printf("\nQuick Sort:\n");
        quick_sort_with_benchmark(array, n, &metrics);
        printf("Tempo: %f s, Comparações: %d, Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);

        free(array); // Libera a memória alocada
    }

    return 0;
}