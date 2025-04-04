#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_generator.h"
#include "benchmark.h"
#include "sorts/bubble_sort.h"
#include "sorts/merge_sort.h"
#include "sorts/quick_sort.h"

int main() {
    int tamanhos[] = {1000, 10000, 100000, 1000000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    int limite_superior = 1000000;
    int repeticoes = 10;
    struct BenchmarkMetrics metrics;

    for (int t = 0; t < num_tamanhos; t++) {
        int n = tamanhos[t];
        int *array = (int *)malloc(n * sizeof(int));
        int *array_copy = (int *)malloc(n * sizeof(int));

        if (array == NULL || array_copy == NULL) {
            printf("Erro ao alocar memória para o array de tamanho %d.\n", n);
            free(array);
            free(array_copy);
            return 1;
        }

        printf("\n==========================\n");
        printf("  TESTANDO TAMANHO: %d\n", n);
        printf("==========================\n");

        if (n <= 10000) {
            printf("\n--- Bubble Sort ---\n");

            gerar_lista_aleatoria(array, n, limite_superior);
            memcpy(array_copy, array, n * sizeof(int));
            printf("Lista Aleatória: ");
            bubble_sort(array_copy, n, &metrics);
            printf("Tempo: %f s | Comparações: %d | Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);

            gerar_lista_reversa(array, n);
            memcpy(array_copy, array, n * sizeof(int));
            printf("Lista Reversa: ");
            bubble_sort(array_copy, n, &metrics);
            printf("Tempo: %f s | Comparações: %d | Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);

            gerar_lista_repetida(array, n, repeticoes);
            memcpy(array_copy, array, n * sizeof(int));
            printf("Lista com Valores Repetidos: ");
            bubble_sort(array_copy, n, &metrics);
            printf("Tempo: %f s | Comparações: %d | Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);
        } else {
            printf("\n[Bubble Sort ignorado para tamanhos > 10000]\n");
        }

        printf("\n--- Merge Sort ---\n");

        gerar_lista_aleatoria(array, n, limite_superior);
        memcpy(array_copy, array, n * sizeof(int));
        printf("Lista Aleatória: ");
        merge_sort_with_benchmark(array_copy, n, &metrics);
        printf("Tempo: %f s | Comparações: %d\n", metrics.tempo_execucao, metrics.comparacoes);

        gerar_lista_reversa(array, n);
        memcpy(array_copy, array, n * sizeof(int));
        printf("Lista Reversa: ");
        merge_sort_with_benchmark(array_copy, n, &metrics);
        printf("Tempo: %f s | Comparações: %d\n", metrics.tempo_execucao, metrics.comparacoes);

        gerar_lista_repetida(array, n, repeticoes);
        memcpy(array_copy, array, n * sizeof(int));
        printf("Lista com Valores Repetidos: ");
        merge_sort_with_benchmark(array_copy, n, &metrics);
        printf("Tempo: %f s | Comparações: %d\n", metrics.tempo_execucao, metrics.comparacoes);

        printf("\n--- Quick Sort ---\n");

        gerar_lista_aleatoria(array, n, limite_superior);
        memcpy(array_copy, array, n * sizeof(int));
        printf("Lista Aleatória: ");
        quick_sort_with_benchmark(array_copy, n, &metrics);
        printf("Tempo: %f s | Comparações: %d | Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);

        gerar_lista_reversa(array, n);
        memcpy(array_copy, array, n * sizeof(int));
        printf("Lista Reversa: ");
        quick_sort_with_benchmark(array_copy, n, &metrics);
        printf("Tempo: %f s | Comparações: %d | Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);

        gerar_lista_repetida(array, n, repeticoes);
        memcpy(array_copy, array, n * sizeof(int));
        printf("Lista com Valores Repetidos: ");
        quick_sort_with_benchmark(array_copy, n, &metrics);
        printf("Tempo: %f s | Comparações: %d | Trocas: %d\n", metrics.tempo_execucao, metrics.comparacoes, metrics.trocas);

        free(array);
        free(array_copy);
    }

    return 0;
}
