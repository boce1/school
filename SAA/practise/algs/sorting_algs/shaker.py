from .swap import swap_elements

def shaker_sort(arr):
    left = 0
    right = len(arr) - 1
    k = left

    while left < right:
        while k < right:
            if arr[k] > arr[k + 1]:
                swap_elements(arr, k, k + 1)
            k += 1
        right -= 1

        while k > left:
            if arr[k] < arr[k - 1]:
                swap_elements(arr, k, k - 1)
            k -= 1
        left += 1

    print("shaker sort: ", end = "")
