def bubblesort(elemento):
    n = len(elemento)
    comparacoes = 0
    trocas = 0
    for i in range(n):
        for j in range(0, n-i-1):
            comparacoes += 1
            if elemento[j] > elemento[j+1]:
                elemento[j], elemento[j+1] = elemento[j+1], elemento[j]
                trocas += 1
    return elemento, comparacoes, trocas