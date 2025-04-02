def mergesort(lista, inicio=0, fim=None, comparacoes=0, trocas=0):
    if fim is None:
        fim = len(lista)
    if(fim - inicio > 1):
        meio = (fim + inicio) // 2
        lista, comparacoes, trocas = mergesort(lista, inicio, meio,comparacoes, trocas)
        lista, comparacoes, trocas = mergesort(lista, meio, fim, comparacoes, trocas)
        lista, comparacoes, trocas = merge(lista, inicio, meio, fim, comparacoes, trocas)
    return lista, comparacoes, trocas

def merge(lista, inicio, meio, fim, comparacoes, trocas):

    left = lista[inicio:meio]
    right = lista[meio:fim]

    top_left, top_right = 0,0

    for k in range(inicio, fim):
        comparacoes += 1
        if top_left >= len(left):
            lista[k] = right[top_right]
            top_right += 1
            trocas += 1
        elif top_right >= len(right):
            lista[k] = left[top_left]
            top_left += 1   
            trocas += 1
        elif left[top_left] < right[top_right]:
            lista[k] = left[top_left]
            top_left += 1
            trocas += 1
        else:
            lista[k] = right[top_right]
            top_right += 1
            trocas += 1
    return lista, comparacoes, trocas