def quicksort(arr, comparacoes=0, trocas=0):
    if len(arr) <= 1:
        return arr, comparacoes, trocas 

    pivot = arr[len(arr) // 2]
    left = []
    middle = []
    right = []

    for x in arr:
        comparacoes += 1
        if x < pivot:
            left.append(x)
            trocas += 1
        elif x > pivot:
            right.append(x)
            trocas += 1
        else:
            middle.append(x)

    left_sorted, comparacoes, trocas = quicksort(left, comparacoes, trocas)
    right_sorted, comparacoes, trocas = quicksort(right, comparacoes, trocas)

    return left_sorted + middle + right_sorted, comparacoes, trocas