def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_el_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_el_index]:
                min_el_index = j
        arr[i], arr[min_el_index] = arr[min_el_index], arr[i]
    
    return arr

l = [1,5,56,5,8,6,1,2,3,22,2,3,5]
selection_sort(l)
print(l)