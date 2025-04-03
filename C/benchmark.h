#ifndef BENCHMARK_H
#define BENCHMARK_H

struct BenchmarkMetrics {
    double tempo_execucao; // Tempo de execução do algoritmo
    int memoria;           // Memória utilizada (em bytes)
    int comparacoes;       // Número de comparações realizadas
    int trocas;            // Número de trocas realizadas
};

#endif