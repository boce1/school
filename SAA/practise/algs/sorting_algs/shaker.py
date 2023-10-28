from .swap import swap_elements

def shaker_sort(arr):
    left = 0
	right = len(arr) - 1
	last_pos = left
	k = left

	while left < right:
		while k < right:
			if arr[k] > arr[k + 1]:
				swap(arr, k, k + 1)
				last_pos = k
			k += 1

		right = last_pos
		k = right

		while k > left:
			if arr[k] < arr[k - 1]:
				swap(arr, k, k - 1)
				last_pos = k
			k -= 1

		left = last_pos
		k = left

    print("shaker sort: ", end = "")
