#include "list_generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_lista_aleatoria(int array[], int n, int limite_superior) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % limite_superior;
    }
}

void gerar_lista_reversa(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = n - i - 1;
    }
}

void gerar_lista_repetida(int array[], int n, int repeticoes) {
    for (int i = 0; i < n; i++) {
        array[i] = i % repeticoes;
    }
}

void imprimir_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
