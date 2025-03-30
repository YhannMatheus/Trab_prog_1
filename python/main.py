from sorts import bubblesort, mergesort, quicksort
import random

def gerar_lista(tamanho=100, limite=1000):
    return random.sample(range(1, limite), tamanho)

if __name__ == "__main__":
    lista = gerar_lista(5)
    print("Lista original:", lista)
    print("Bubble Sort:", bubblesort(lista[:]))
    print("Merge Sort:", mergesort(lista[:]))