from sorts import bubblesort, mergesort, quicksort
from time import time
import tracemalloc
import random


def gerar_lista_ordenada(tamanho=1000000, inverter=False):
    if inverter:
        return list(range(tamanho, 0, -1 ))
    return list(range(1, tamanho + 1))

def gerar_lista_aleatoria(tamanho=1000000, limite=1000000, repeticoes=False):
    if repeticoes:
        return random.choices(range(1, limite), k=tamanho)
    return random.sample(range(0, limite), tamanho)

def ordenar_lista(algoritmo, lista):   
    lista_copia = lista[:]

    tracemalloc.start()
    inicio_temp = time()
    lista_ordenada, comparacoes, trocas = algoritmo(lista_copia)
    fim_temp = time()
    mem_atual, mem_pico = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    #print(lista_ordenada)
    print(f'Algoritmo: {algoritmo.__name__}') 
    print(f'Memória consumida: {mem_pico / 1024 / 1024:.4f} MiB')
    print(f'Tempo de execução: {fim_temp-inicio_temp} Segundos')
    print(f'Comparações: {comparacoes} trocas: {trocas}\n')
    

if __name__ == "__main__":
    lista_aleatoria = gerar_lista_aleatoria(5, 10)
    lista_ordenada = gerar_lista_ordenada(5)

    ordenar_lista(bubblesort, lista_aleatoria)
    ordenar_lista(mergesort, lista_aleatoria)
    ordenar_lista(quicksort, lista_aleatoria)