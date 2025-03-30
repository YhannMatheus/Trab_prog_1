from sorts import bubblesort, mergesort, quicksort
from time import time
import random

def gerar_lista_aleatoria(tamanho=100, limite=1000):
    return random.sample(range(1, limite), tamanho)

if __name__ == "__main__":
    listaAleatoria = gerar_lista_aleatoria(999) # Gerando uma lista de números aleatórios
    print("Lista original:", listaAleatoria)

    inicio = time() 
    print("Bubble Sort:", bubblesort(listaAleatoria[:])) # Alterne o algorimo de ordenação aqui
    fim = time()
    print(f'O tempo de execução foi: {fim-inicio}ms')