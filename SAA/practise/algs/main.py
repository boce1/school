import test
import sorting_algs

size = 10

arr_t = test.generate_arr(size)
test.test_sort(lambda : sorting_algs.buble_sort(arr_t), arr_t)

arr_t = test.generate_arr(size)
test.test_sort(lambda : sorting_algs.selection_sort(arr_t), arr_t)

arr_t = test.generate_arr(size)
test.test_sort(lambda : sorting_algs.merge_sort(arr_t), arr_t)

arr_t = test.generate_arr(size)
test.test_sort(lambda : sorting_algs.insertion_sort(arr_t), arr_t)

arr_t = test.generate_arr(size)
test.test_sort(lambda : sorting_algs.shaker_sort(arr_t), arr_t)

arr_t = test.generate_arr(size)
test.test_sort(lambda : sorting_algs.shell_sort(arr_t), arr_t)