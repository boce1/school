def input_number(promt, error_msg, is_possitive = True):
    while True:
        try:
            x = int(input(promt))
            if is_possitive and x <= 0:
                raise Exception("Number must be possitive")
            return x
        except ValueError:
            print(error_msg)
        except Exception as e:
            print(e)

n = input_number("N = ", "Invalid number N")
k = input_number("K = ", "Invalid number K")
nums = [input_number("x = ", "Invalid x", False) for _ in range(n)]

nums1 = [x for x in nums if x > k]

import functools
print(functools.reduce(lambda x, y: x * y, [nums1[i] for i in range(1, len(nums1), 2)]))

if len(nums1) > 0:
    print(nums1.index(min(nums1)))
else:
    print("No such date")

nums2 = [x for x in nums if x <= k and x > 0]
if len(nums2) > 0:
    print(max(nums2) - min(nums2))
else:
    print("no such data")