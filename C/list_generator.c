#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_array_aleatorio(int array[], int n, int limite_superior) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % limite_superior;
    }
}


void imprimir_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}